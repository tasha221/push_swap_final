/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_final_ra2(t_stack *a, char **res, int i_min)
{
	if (i_min < a->size / 2)
	{
		while (i_min)
		{
			rotate(a, res);
			i_min--;
		}
	}
	else
	{
		while (i_min < a->size)
		{
			rrotate(a, res);
			i_min++;
		}
	}
}

void	make_final_ra(t_stack *a, char **res)
{
	int		i;
	int		i_min;
	t_elem	*ae;
	int		min;

	ae = a->first;
	i_min = 0;
	i = 0;
	min = ae->n;
	while (ae)
	{
		if (ae->n < min)
		{
			min = ae->n;
			i_min = i;
		}
		ae = ae->next;
		i++;
	}
	make_final_ra2(a, res, i_min);
}
