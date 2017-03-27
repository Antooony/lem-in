/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:12:02 by adenis            #+#    #+#             */
/*   Updated: 2017/03/27 22:10:01 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdio.h>

void	display_lst(t_list	*lst)
{
	ft_printf("%s\n", (char *)lst->content);
	lst->next ? display_lst(lst->next) : NULL;
}

void	init_infos(void)
{
	infos.begin = NULL;
	infos.start = NULL;
	infos.end = NULL;
}

int		main(void)
{

	t_list	*lst;
	t_list	*tmp;

	lst = ft_lstnew(NULL, 0);
	tmp = ft_lstnew(NULL, 0);
	while (get_next_line(0, lst->content ? LTMP : LLST) > 0)
	{
		if (tmp->content)
		{
			ft_lstadd_end(lst, tmp);
			tmp = tmp->next;
			tmp = ft_lstnew(NULL, 0);
		}
	}
	parsing(lst);
}