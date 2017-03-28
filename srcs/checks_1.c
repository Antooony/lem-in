/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:56:02 by adenis            #+#    #+#             */
/*   Updated: 2017/03/28 17:17:38 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

int			isroom(char *s)
{
	t_room		*room;

	room = BEGIN;
	while (room)
	{
		if (!ft_strcmp(room->name, s))
			return (1);
		room = room->next;
	}
	return (0);
}

int			islink(char *s)
{
	char	*tmp;
	char	*tmp2;
	int		out;

	out = 0;
	tmp = NULL;
	tmp2 = NULL;
	if (!ft_strchr(s, '-') || !(ft_strchr(s, '-') - s) 
		|| (size_t)(ft_strchr(s, '-') - s) == ft_strlen(s)) 
		return (0);
	tmp = ft_strsub(s, 0, ft_strchr(s, '-') - s);
	tmp2 = ft_strchr(s, '-') + 1;
	tmp2 = ft_strsub(s, ft_strchr(s, '-') + 1 - s, 
		ft_strlen(s) - (ft_strchr(s, '-') - s));
	if (isroom(tmp) && isroom(tmp2))
		out = 1;
	return (out);
}

int			isox(char *s)
{
	if (!s || !ft_strchr(s, ' ')
		|| !ft_isdigit(s[ft_strchr(s, ' ') + 1 - s]) 
			|| !ft_isdigit(s[ft_strrchr(s, ' ') + 1 - s]))
			return (0);
	return (1);
}

int			islimit(char *s)
{
	if (!ft_strcmp(s, "##start") || !ft_strcmp(s, "##end"))
		return (1);
	return (0);
}

int			iscomment(char *s)
{
	if (s[0] == '#'	&& ft_strcmp(s, "##start")
		&& ft_strcmp(s, "##end"))
		return (1);
	return (0);
}
