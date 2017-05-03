/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:02:28 by adenis            #+#    #+#             */
/*   Updated: 2017/05/03 06:45:19 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

void		reverse_path(t_path *path, t_path *tmp)
{
	if (path->next == FINISH)
		path->next = NULL;
	if (path != FINISH && path->next)
		reverse_path(path->next, tmp);
	ft_lstadd((t_list **)&tmp, (t_list *)path);
	ft_printf("%s\n", tmp->content);
}

void		check_path(t_list *path)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	if (!path)
		leave();
	while (path)
	{
		if (!ft_strcmp((char *)path->content, START->name))
			start = 1;
		if (!ft_strcmp((char *)path->content, END->name))
			end = 1;
		path = path->next;
	}
	if (!end || !start)
		leave();
}

void		parsing_2(t_list *lst)
{
	t_path *tmp;
	check_up();
	while(!islink(LINE) || iscomment(LINE))
		lst = lst->next;
	while (lst)
	{
		iscomment(LINE) ? NULL : get_links(LINE);
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	get_path(START);
	check_path((t_list *)PATH);
	tmp = NULL;
	// display_lst((t_list *)PATH);
	// reverse_path(PATH, tmp);
	// display_lst((t_list *)tmp);
	// resolution();
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
		if (iscomment(LINE))
			lst = lst->next;
		else if (!ft_strcmp(LINE, "##start") || !ft_strcmp(LINE, "##end"))
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
 