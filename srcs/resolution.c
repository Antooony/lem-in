/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:42:19 by adenis            #+#    #+#             */
/*   Updated: 2017/05/03 12:45:50 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

int			check(void)
{
	t_path		*tmp;

	tmp = BEGIN;
	if (ANTS - VAL)
		return (1);
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->ant)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		showit(void)
{
	t_path *tmp;

	tmp = BEGIN;
	while (tmp)
	{
		ft_printf("%s : %d -- ",tmp->content, tmp->ant);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int			handle_ants(void)
{
	ft_printf("\n");
	if (ANTS - VAL)
	{
		VAL++;
		return(VAL);
	}
	else
		return(0);
}

void		move(t_path *tmp)
{
	tmp->ant = tmp->next->ant;
	tmp->next->ant = 0;
	ft_printf("L%d-%s ", tmp->ant, tmp->content);
}

void		resolution(void)
{
	t_path	*tmp;

	tmp = BEGIN;
	while (tmp && check())
	{
		if (tmp == FINISH)
		{
			tmp->ant = handle_ants();
			tmp = BEGIN;
		}
		if (tmp->next->ant)
			move(tmp);
		else if (tmp->ant &&!tmp->next->ant)
		{
			ft_printf("\n");
			tmp = BEGIN;
		}
		tmp = tmp->next;
	}
	ft_printf("\n");
}