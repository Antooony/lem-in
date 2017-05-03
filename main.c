/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:12:02 by adenis            #+#    #+#             */
/*   Updated: 2017/05/03 12:50:44 by adenis           ###   ########.fr       */
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
			leave("Error on ants number");
		i++;
	}
	if (ft_atol(s) > 2147483647 || ft_atol(s) <= 0)
		leave("Error on ants number");
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
			leave("Bad input");
		lst = lst->next;
	}
	if (!rooms || !links)
		leave("Bad input");
}

void	display_input(t_list *lst)
{
	while (lst)
	{
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
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

void	init_shit(void)
{
	g_infos.path = NULL;
	g_infos.ants = 0;
	g_infos.val = 0;
	g_infos.begin = NULL;
	g_infos.finish = NULL;
	g_infos.tmp = NULL;
	g_infos.first = NULL;
	g_infos.start = NULL;
	g_infos.end = NULL;
}

int		main(void)
{
	t_list	*lst;
	t_list	*tmp;

	lst = ft_lstnew(NULL, 0);
	tmp = ft_lstnew(NULL, 0);
	init_shit();
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
	tmp = ft_lstdup(lst);
	clean_lst(lst);
	parsing(lst);
	display_input(tmp);
	ft_lstdel(&tmp, &del);
	ft_lstdel(&lst, &del);
	resolution();
	ft_lstdel((t_list **)&BEGIN, &del);
	// while(42);
}
