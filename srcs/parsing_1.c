/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:02:28 by adenis            #+#    #+#             */
/*   Updated: 2017/05/03 12:50:01 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

void		relink(t_path *path)
{
	if (path->next == BEGIN)
		TMP->next = NULL;
	if (path->next)
		relink(path->next);
	if (!TMP->content)
		TMP->content = ft_strdup(path->content);
	else
	{
		TMP->next = (t_path *)ft_lstdup((t_list *)path);
		TMP = TMP->next;
	}
}

void		reverse_path(t_path *path)
{
	t_path		*start;

	TMP = (t_path *)ft_lstnew(NULL, 0);
	start = TMP;
	relink(path);
	TMP = start;
	while (TMP)
	{
		TMP->ant = 0;
		if (!ft_strcmp(TMP->content,START->name))
		{
			ft_lstdel((t_list **)&TMP->next, &del);
			TMP->next = NULL;
			FINISH = TMP;
		}
		TMP = TMP->next;
	}
	TMP = start;
	ft_lstdel((t_list **)&PATH, &del);
	PATH = TMP;
	BEGIN = PATH;
}

void		check_path(t_list *path)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	if (!path)
		leave("No path");
	while (path)
	{
		if (!ft_strcmp((char *)path->content, START->name))
			start = 1;
		if (!ft_strcmp((char *)path->content, END->name))
			end = 1;
		path = path->next;
	}
	if (!end || !start)
		leave("NO end or start");
}

void		cleanrooms(t_room *room1)
{
	if (room1->next)
		cleanrooms(room1->next);
	free(LINK);
	if (room1->name)
		ft_strdel(&room1->name);
	free(room1);
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
	check_path((t_list *)PATH);
	reverse_path(PATH);
	cleanrooms(START);
}

void		parsing(t_list *lst)
{
	t_room	*room;

	room = ft_newroom();
	FIRST = room;
	ft_isdigit(LINE[0]) ? ANTS = ft_atoi(LINE) : leave("Ants issue");
	lst = lst->next;
	while (lst)
	{
		if (!isvalid(LINE))
			leave("");
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
 