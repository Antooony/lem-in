/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:02:28 by adenis            #+#    #+#             */
/*   Updated: 2017/03/28 18:33:33 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

void		get_limits(t_room *room, t_list *lst)
{
	if (!ft_strcmp(LINE, "##start"))
	{
		room->start = 1;
		START = room;
	}
	if (!ft_strcmp(LINE, "##end"))
	{
		room->end = 1;
		END = room;
	}
}

void		parsing(t_list	*lst)
{
	t_room	*room;

	room = ft_newroom();
	BEGIN = room;
	if (ft_isdigit(LINE[0]))
		ANTS = ft_atoi(LINE);
	else
		exit (0);
	lst = lst->next;
	while (lst)
	{
		if (!isvalid(LINE))
		{
			ft_printf("Invalid : %s\n", LINE);
			exit(0);
			break ;
		}
		if (!ft_strcmp(LINE, "##start") || !ft_strcmp(LINE, "##end"))
		{
			get_limits(room, lst);
			lst = lst->next;
		}
		room = fill_room(room, lst);
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	display_rooms((room = BEGIN));
}