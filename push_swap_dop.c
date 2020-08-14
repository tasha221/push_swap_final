/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	for_five2(char **res, t_stack *a, t_stack *b, int *mas)
{
	if (a->last->n == mas[0])
		rrotate(a, res);
	else
	{
		while (a->first->n != mas[0])
			rotate(a, res);
	}
	push(a, b, res);
	push(a, b, res);
	rotate(a, res);
	rotate(a, res);
}

char	*make_for_five(t_stack *a, t_stack *b, int *mas)
{
	char		*res;

	res = ft_strnew(0);
	while (a->size > 3)
	{
		if (a->first->n == mas[3] || a->first->n == mas[4])
			push(b, a, &res);
		else if (a->last->n == mas[3] || a->last->n == mas[4])
		{
			rrotate(a, &res);
			push(b, a, &res);
		}
		else
			rotate(a, &res);
	}
	if (!is_cycled(a))
		swap(a, &res);
	if (b->first->n < b->last->n)
		swap(b, &res);
	for_five2(&res, a, b, mas);
	return (res);
}

int		push_swap2(t_stack *a, t_stack *b, char **arr, int *mas)
{
	char	*res;
	int		i;

	if (is_sorted(a, b))
	{
		free_arr(arr);
		free(mas);
		free_stack(a);
		free_stack(b);
		return (0);
	}
	i = arr_len(arr);
	bubble(i - 1, mas);
	if (a->size == 5)
		res = make_for_five(a, b, mas);
	else
		res = sort(a, b, mas);
	ft_printf("%s", res);
	i = 0;
	free_arr(arr);
	free(res);
	free(mas);
	free_stack(a);
	free_stack(b);
	return (0);
}
