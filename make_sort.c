/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_rarb(t_stack *stacks[2], char **res, int ra, int rb)
{
	while (ra && rb)
	{
		rotate(stacks[0], res);
		rotate(stacks[1], res);
		ra--;
		rb--;
	}
	while (ra)
	{
		rotate(stacks[0], res);
		ra--;
	}
	while (rb)
	{
		rotate(stacks[1], res);
		rb--;
	}
}

void	make_rrarrb(t_stack *stacks[2], char **res, int ra, int rb)
{
	while (ra < stacks[0]->size && rb > 0)
	{
		rrotate(stacks[0], res);
		rrotate(stacks[1], res);
		ra++;
		rb--;
	}
	while (ra < stacks[0]->size)
	{
		rrotate(stacks[0], res);
		ra++;
	}
	while (rb > 0)
	{
		rrotate(stacks[1], res);
		rb--;
	}
}

void	make_rrarb(t_stack *stacks[2], char **res, int ra, int rb)
{
	while (ra < stacks[0]->size)
	{
		rrotate(stacks[0], res);
		ra++;
	}
	while (rb)
	{
		rotate(stacks[1], res);
		rb--;
	}
}

void	make_rarrb(t_stack *stacks[2], char **res, int ra, int rb)
{
	while (ra)
	{
		rotate(stacks[0], res);
		ra--;
	}
	while (rb > 0)
	{
		rrotate(stacks[1], res);
		rb--;
	}
}

void	make_push(t_stack *a, t_stack *b, int j, char **res)
{
	int		rb;
	int		ra;
	t_elem	*be;
	int		i;

	rb = (j < b->size / 2) ? j : b->size - j;
	i = 0;
	be = b->first;
	while (i < j)
	{
		be = be->next;
		i++;
	}
	ra = find_min_a(a, be->n, 0);
	if (ra < a->size / 2 && j < b->size / 2)
		make_rarb((t_stack*[2]){a, b}, res, ra, rb);
	else if (ra >= a->size / 2 && j >= b->size / 2)
		make_rrarrb((t_stack*[2]){a, b}, res, ra, rb);
	else if (ra >= a->size / 2 && j < b->size / 2)
		make_rrarb((t_stack*[2]){a, b}, res, ra, rb);
	else if (ra < a->size / 2 && j >= b->size / 2)
		make_rarrb((t_stack*[2]){a, b}, res, ra, rb);
	push(a, b, res);
}
