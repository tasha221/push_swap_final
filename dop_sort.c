/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble(int size, int *mas)
{
	int		tmp;
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		{
			while (j < size - 1)
			{
				if (mas[j] > mas[j + 1])
				{
					tmp = mas[j];
					mas[j] = mas[j + 1];
					mas[j + 1] = tmp;
				}
				j++;
			}
		}
		i++;
	}
}

int		f_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		find_best_i(t_stack *a, int max, int fl)
{
	int		i_max;
	int		i;
	t_elem	*ae;

	i = 0;
	ae = a->first;
	i_max = 0;
	while (i < a->size)
	{
		if (ae->n == max)
			i_max = i;
		ae = ae->next;
		i++;
	}
	if (fl)
		return (f_min(i_max, a->size - i_max));
	else
		return (i_max);
}

int		find_min_a(t_stack *a_stack, int num, int fl)
{
	t_elem	*a;
	int		min;
	int		max;

	a = a_stack->first;
	min = a->n;
	while (a)
	{
		if (a->n < num && ((a->n > min && min < num) ||
			(min > num && min > a->n)))
			min = a->n;
		a = a->next;
	}
	a = a_stack->first;
	max = a->n;
	while (a)
	{
		if (a->n > num && ((a->n < max && max > num) ||
			(max < num && a->n > num)))
			max = a->n;
		a = a->next;
	}
	return (find_best_i(a_stack, max, fl));
}

int		*make_mas_num(t_stack *a, t_stack *b, int *num)
{
	t_elem	*be;
	int		i;
	int		buf;

	be = b->first;
	i = 0;
	while (i < b->size)
	{
		if (i < b->size / 2)
			buf = i;
		else
			buf = b->size - i;
		num[i] = buf + find_min_a(a, be->n, 1);
		be = be->next;
		i++;
	}
	return (num);
}
