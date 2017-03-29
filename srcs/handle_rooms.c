/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:13:24 by adenis            #+#    #+#             */
/*   Updated: 2017/03/29 19:16:41 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

void		display_rooms(t_room *room1)
{
	t_room 	*tmp;
	t_list 	*lst;
	ft_printf("%-10s", room1->name);
	if (room1 == START)
		ft_printf("\t\t\t\t--START\n");
	else if (room1 == END)
		ft_printf("\t\t\t\t--END\n");
	else
		ft_printf("\n");
	if (LINK)
	{
		lst = LINK;
		while (LINK)
		{
			tmp = LINK->content;
			ft_printf("\t->%s\n", tmp->name);
			LINK = LINK->next;
		}
		LINK = lst;
	}
	room1->next ? display_rooms(room1->next) : NULL;
}

t_room		*ft_newroom(void)
{
	t_room	*new;

	new = (t_room *)malloc(sizeof(t_room));
	new->next = NULL;
	new->name = NULL;
	new->links = NULL;
	new->end = 0;
	new->start = 0;
	new->stop = 0;
	new->track = 0;
	return (new);
}

t_room		*fill_room(t_room *room, t_list *lst)
{
	if (!isox(LINE))
		return (room);
	room->name = ft_strsub(LINE, 0, ft_strchr(LINE, ' ') - LINE);
	if (lst->next && still_ox(lst->next))
	{
		room->next = ft_newroom();
		room = room->next;
	}
	return (room);
}

void		set_link(t_room *room1, t_room *room2)
{
	t_list	*tmp;

	tmp = ft_lstnew(NULL, 0);
	tmp->content = room2;
	if (!room1->links)
		room1->links = tmp;
	else
		ft_lstadd_end(room1->links, tmp);
}	

void		link_rooms(t_room *room1, t_room *room2)
{
	if (!islinked(room1, room2))
		set_link(room1, room2);
	if (!islinked(room2, room1))
		set_link(room2, room1);
}
