/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:02:28 by adenis            #+#    #+#             */
/*   Updated: 2017/03/29 20:53:12 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

void		set_way(void)
{
		BEGIN = PATH->start;
		while (PATH->next)
			PATH = PATH->next;
		FINISH = PATH;
}

void		parsing_2(t_list *lst)
{
	check_up();
	while(!islink(LINE))
		lst = lst->next;
	while (lst)
	{
		get_links(LINE);
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	get_path(START);
	display_lst((t_list *)PATH);
	set_way();
	resolution();
}

void		parsing(t_list *lst)
{
	t_room	*room;

	room = ft_newroom();
	FIRST = room;
	ft_isdigit(LINE[0]) ? ANTS = ft_atoi(LINE) : leave();
	lst = lst->next;
	while (lst)
	{
		if (!isvalid(LINE))
			leave();
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
	parsing_2(lst->start);
}
 