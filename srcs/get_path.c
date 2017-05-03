/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:54:20 by adenis            #+#    #+#             */
/*   Updated: 2017/05/03 10:39:31 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

int		get_path(t_room *room1)
{
	t_room		*tmp;
	t_list		*out;

	if (room1->track)
		return (0);
	if (room1 == END)
		return (1);
	while (LINK)
	{
		tmp = LINK->content;
		room1->track = 1;
		if (get_path(LINK->content))
		{
			out = ft_lstnew(tmp->name, ft_strlen(tmp->name));
			ft_lstadd((t_list**)&PATH, out);
			if (room1 == START)
				ft_lstadd((t_list **)&PATH, ft_lstnew(room1->name, 
					ft_strlen(room1->name)));
			return (1);
		}
		if (!LINK->next)
			break;
		LINK = LINK->next;
	}
	return (0);
}
