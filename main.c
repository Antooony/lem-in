/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:12:02 by adenis            #+#    #+#             */
/*   Updated: 2017/05/03 06:45:08 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include <stdio.h>

void	check_ants(char *s)
{
	int i;
	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			leave();
		i++;
	}
}

void	pre_check(t_list *lst)
{
	int		rooms;
	int		links;

	rooms = 0;
	links = 0;
	check_ants(lst->content);
	while (lst)
	{
		if (ft_strchr(lst->content, '-'))
			links = 1;
		if (isox(lst->content))
			rooms = 1;
		if ((ft_strchr(lst->content, '-') && !rooms)
			|| (isox(lst->content) && links))
			leave();
		lst = lst->next;
	}
	if (!rooms || !links)
		leave();
}

void	display_input(t_list *lst)
{
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
}

void	set_way(void)
{
		BEGIN = PATH->start;
		while (PATH->next)
			PATH = PATH->next;
		FINISH = PATH;
}

t_list *ft_lstdup(t_list *lst)
{
	t_list		*tmp;
	t_list		*start;

	tmp = ft_lstnew(lst->content, ft_strlen(lst->content));
	start = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(lst->content, ft_strlen(lst->content));
		tmp = tmp->next;
		lst = lst->next;
	}
	return (start);
}

t_list	*clean_lst(t_list *list1)
{
	t_list		*start;
	t_list		*tmp;
	t_list		*lst;

	lst = ft_lstdup(list1);
	start = lst;
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
	return (start);
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
	pre_check(lst);
	tmp = lst;
	lst = clean_lst(lst);
	parsing(lst);
	display_input(tmp);
	display_lst((t_list *)PATH);
	set_way();
	ft_lstdel(&lst, &del);
}
