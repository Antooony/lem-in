/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:02:28 by adenis            #+#    #+#             */
/*   Updated: 2017/03/27 22:42:19 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

int			check_ox(char *s)
{
	if (!s || !ft_strchr(s, ' ')
		|| !ft_isdigit(s[ft_strchr(s, ' ') + 1 - s]) 
			|| !ft_isdigit(s[ft_strrchr(s, ' ') + 1 - s]))
			return (0);
	return (1);
}

void		get_limits(t_room *room, t_list *lst)
{
	if (!ft_strcmp(LINE, "##start"))
	{
		room->start = 1;
		START = room;
	}
	if (!ft_strcmp(LINE, "##end"))
	{
		ft_printf("END\n");
		room->end = 1;
		END = room;
	}
}

void		parsing(t_list	*lst)
{
	t_room	*room;

	room = ft_newroom();
	BEGIN = room;
	while (lst)
	{
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
	ft_printf("Start : %s\n", START->name);
	ft_printf("end : %s\n", END->name);
}