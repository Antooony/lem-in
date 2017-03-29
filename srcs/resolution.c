/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 20:42:19 by adenis            #+#    #+#             */
/*   Updated: 2017/03/29 20:58:17 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in.h"

void		movup(void)
{
	t_path	*tmp;

	tmp = BEGIN;
	while (tmp != FINISH)
	{
		if (!tmp->ant)
		{
			ant = 1;
		}
		tmp = tmp->next;
	}
}

void		resolution(void)
{
	while (ANTS)
	{
		movup();
	}
}