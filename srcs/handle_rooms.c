/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 19:13:24 by adenis            #+#    #+#             */
/*   Updated: 2017/03/28 16:55:23 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

void		display_rooms(t_room *room)
{
	ft_printf("%-10s", room->name);
	if (room->start)
		ft_printf(" --    ##START\n");
	else if (room->end)
		ft_printf(" --    ##END\n");
	else
		ft_printf("\n");
	room->next ? display_rooms(room->next) : NULL;
}

t_room		*ft_newroom(void)
{
	t_room	*new;

	new = (t_room *)malloc(sizeof(t_room));
	new->next = NULL;
	new->name = NULL;
	new->connexions = NULL;
	new->end = 0;
	new->start = 0;
	new->stop = 0;
	return (new);
}

int			still_ox(t_list *lst)
{
	while (lst)
	{
		if (LINE[0] == '#')
		{
			lst = lst->next;
			continue ;
		}
		if (isox(LINE))
			return (1);
		else
			return (0);
		lst = lst->next;
	}
	return (0);
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
