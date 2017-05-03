/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:34:27 by adenis            #+#    #+#             */
/*   Updated: 2017/04/17 09:14:42 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

void	freelst(void *content, size_t content_size)
{
	content_size = 0;
	free(content);
	content = NULL;
}

void	del(void *content, size_t size)
{
	if (content)
		free(content);
	content = NULL;
	size = 0;
}

void	display_lst(t_list	*lst)
{
	while (lst)
	{
		ft_printf("%s", (char *)lst->content);
		if (lst->next)
			ft_printf("->");
		lst = lst->next;
	}
	ft_putchar('\n');
}

void	init_infos(void)
{
	g_infos.begin = NULL;
	g_infos.end = NULL;
	g_infos.first = NULL;
	g_infos.start = NULL;
	g_infos.end = NULL;
	g_infos.path = (t_path *)ft_lstnew(NULL, 0);
}

void		leave(void)
{
	ft_printf("error\n");
	exit (0);
}
