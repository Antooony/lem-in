/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:12:02 by adenis            #+#    #+#             */
/*   Updated: 2017/03/28 16:27:08 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdio.h>

void	clean_lst(t_list *lst)
{
	t_list		*tmp;

	while (lst)
	{
		if (lst->next && iscomment((char *)lst->next->content))
		{
			tmp = lst->next->next;
			ft_lstdelone(&lst->next, &del);
			lst->next = tmp;
			continue ;
		}
		lst = lst->next;
	}
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
	clean_lst(lst);
	parsing(lst);
}
