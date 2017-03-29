/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:33:31 by adenis            #+#    #+#             */
/*   Updated: 2017/03/29 18:04:59 by adenis           ###   ########.fr       */
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

t_room		*get_room(char *s)
{
	t_room		*room;

	room = FIRST;
	while (room)
	{
		if (!ft_strcmp(room->name, s))
			return (room);
		room = room->next;
	}
	return (NULL);
}

void		get_links(char *s)
{
	char 	*tmp;
	char 	*tmp2;
	t_room	*room1;
	t_room	*room2;
	
	tmp = ft_strsub(s, 0, ft_strchr(s, '-') - s);
	tmp2 = ft_strsub(s, ft_strchr(s, '-') + 1 - s, 
		ft_strlen(s) - (ft_strchr(s, '-') - s));
	room1 = get_room(tmp);
	room2 = get_room(tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	link_rooms(room1, room2);
}
