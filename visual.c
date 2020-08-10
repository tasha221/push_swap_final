/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	visual(t_stack *astack, t_stack *bstack)
{
	t_elem	*a;
	t_elem	*b;

	a = astack->first;
	b = bstack->first;
	while (a || b)
	{
		if (a && b)
		{
			ft_printf("%-5d %-5d\n", a->n, b->n);
			a = a->next;
			b = b->next;
		}
		else if (a && !b)
		{
			ft_printf("%-11d\n", a->n);
			a = a->next;
		}
		else
		{
			ft_printf("      %-5d\n", b->n);
			b = b->next;
		}
	}
	ft_printf("__a__ __b__\n\n");
}
