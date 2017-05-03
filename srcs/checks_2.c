/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:56:02 by adenis            #+#    #+#             */
/*   Updated: 2017/05/03 07:03:57 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

int			isvalid(char *s)
{
	if (s[0] != 'L' && (islimit(s) || isox(s) || iscomment(s) || islink(s)))
		return (1);
	return (0);
}

int			islinked(t_room *room1, t_room *room2)
{
	t_list *tmp;

	if (!LINK || !LINK->content)
		return (0);
	tmp = LINK;
	while (LINK && LINK->content)
	{
		if (LINK->content == room2)
			return (1);
		LINK = LINK->next;
	}
	LINK = tmp;
	return (0);
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

void		check_up(void)
{
	if (!START || !END || !FIRST || START == END)
		leave("Limits");
}
