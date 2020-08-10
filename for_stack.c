/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem		*make_elem(int n)
{
	t_elem	*elem;

	elem = (t_elem*)malloc(sizeof(t_elem));
	elem->n = n;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

t_stack		*make_stack(int *mas, int size, int name, int fl)
{
	t_stack	*stack;
	t_elem	*elem;
	int		i;

	stack = (t_stack*)malloc(sizeof(t_stack));
	stack->first = NULL;
	stack->last = NULL;
	stack->name = name;
	stack->size = size;
	i = 0;
	while (i < size)
	{
		elem = make_elem(mas[i]);
		if (i == 0)
			stack->first = elem;
		if (stack->last)
			stack->last->next = elem;
		elem->prev = stack->last;
		stack->last = elem;
		i++;
	}
	if (fl && mas)
		free(mas);
	return (stack);
}

int			is_sorted(t_stack *a, t_stack *b)
{
	int		res;
	int		i;
	t_elem	*tmp;

	if (b->size != 0)
		return (0);
	if (a->size == 1 || a->size == 0)
		return (1);
	i = 1;
	res = 1;
	tmp = a->first->next;
	while (i < a->size)
	{
		if (tmp->prev)
		{
			if (tmp->prev->n > tmp->n)
				res = 0;
		}
		tmp = tmp->next;
		i++;
	}
	return (res);
}

void		free_stack(t_stack *stack)
{
	t_elem	*first;
	t_elem	*cur;

	first = stack->first;
	while (first)
	{
		cur = first;
		first = first->next;
		free(cur);
	}
	free(stack);
}
