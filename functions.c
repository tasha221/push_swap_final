/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char **res)
{
	t_elem *tmp;

	if (stack->size < 2)
		return ;
	if (stack->name == 1)
		ft_strcat2(res, "sa\n");
	else
		ft_strcat2(res, "sb\n");
	tmp = stack->first;
	stack->first = tmp->next;
	tmp->prev = stack->first;
	if (stack->size == 2)
	{
		tmp->next = NULL;
	}
	if (stack->size > 2)
	{
		tmp->next = stack->first->next;
		stack->first->next->prev = tmp;
	}
	stack->first->prev = NULL;
	stack->first->next = tmp;
	if (stack->size == 2)
		stack->last = stack->first->next;
}

void	push(t_stack *to, t_stack *from, char **res)
{
	t_elem	*tmp;

	(from->size > 0 && to->name == 1) ? ft_strcat2(res, "pa\n") :
	ft_strcat2(res, "pb\n");
	if (to->size && from->size)
	{
		tmp = from->first;
		from->first = tmp->next;
		tmp->next = to->first;
		to->first->prev = tmp;
		to->first = tmp;
		to->size += 1;
		from->size -= 1;
	}
	else if (from->size)
	{
		to->first = from->first;
		from->first = from->first->next;
		to->first->next = NULL;
		to->last = to->first;
		to->size += 1;
		from->size -= 1;
	}
	if (from->size > 1)
		from->first->prev = NULL;
}

void	rotate(t_stack *stack, char **res)
{
	t_elem *tmp;

	if (stack->size < 2)
		return ;
	if (stack->name == 1)
		ft_strcat2(res, "ra\n");
	else
		ft_strcat2(res, "rb\n");
	tmp = stack->first;
	stack->first = stack->first->next;
	tmp->next = NULL;
	stack->first->prev = NULL;
	stack->last->next = tmp;
	tmp->prev = stack->last;
	stack->last = tmp;
	if (stack->size == 2)
		stack->first->next = stack->last;
}

void	rrotate(t_stack *stack, char **res)
{
	t_elem	*tmp;

	if (stack->size < 2)
		return ;
	if (stack->name == 1)
		ft_strcat2(res, "rra\n");
	else
		ft_strcat2(res, "rrb\n");
	tmp = stack->last;
	stack->last = stack->last->prev;
	stack->last->next = NULL;
	tmp->prev = NULL;
	tmp->next = stack->first;
	stack->first->prev = tmp;
	stack->first = tmp;
	if (stack->size == 2)
		stack->last->prev = stack->first;
}

int		*make_mas(char **argv, int argc)
{
	int		*res;
	int		i;
	int		j;

	j = 1;
	if (ft_strequ(argv[1], "-v"))
		j = 2;
	res = (int*)malloc(sizeof(int) * argc - j);
	i = 0;
	while (j < argc)
	{
		res[i] = ft_atoi(argv[j]);
		i++;
		j++;
	}
	return (res);
}
