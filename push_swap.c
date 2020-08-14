/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_cycled(t_stack *a)
{
	int		*buf;
	int		j;
	int		tmp;

	buf = (int*)malloc(sizeof(int) * 3);
	buf[0] = a->first->n;
	buf[1] = a->first->next->n;
	buf[2] = a->last->n;
	j = 0;
	while (j < 3)
	{
		if (buf[0] < buf[1] && buf[1] < buf[2])
		{
			free(buf);
			return (1);
		}
		tmp = buf[2];
		buf[2] = buf[1];
		buf[1] = buf[0];
		buf[0] = tmp;
		j++;
	}
	free(buf);
	return (0);
}

int		find_i(int *num, int len)
{
	int		i;
	int		min;
	int		i_res;

	i = 0;
	min = num[0];
	i_res = 0;
	while (i < len)
	{
		if (num[i] < min)
		{
			i_res = i;
			min = num[i];
		}
		i++;
	}
	return (i_res);
}

void	min_max(t_stack *a, t_stack *b, char **res)
{
	int		*num;
	int		j;

	if (!is_cycled(a))
		swap(a, res);
	j = 0;
	while (b->size > 0)
	{
		num = (int*)malloc(sizeof(int) * b->size);
		num = make_mas_num(a, b, num);
		j = find_i(num, b->size);
		make_push(a, b, j, res);
		free(num);
	}
	make_final_ra(a, res);
}

char	*sort(t_stack *a, t_stack *b, int *mas)
{
	char	*res;
	int		len;
	t_elem	*tmp;

	res = ft_strnew(0);
	len = a->size - 1;
	tmp = a->first;
	while (a->size > 3)
	{
		if (tmp->n != mas[0] && tmp->n != mas[len] && tmp->n
			!= mas[len / 2 + 1])
		{
			push(b, a, &res);
			tmp = a->first;
		}
		else
		{
			rotate(a, &res);
			tmp = a->first;
		}
	}
	min_max(a, b, &res);
	return (res);
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			*mas;
	char		**arr;
	int			i;

	i = 0;
	arr = argvdup(argc, argv);
	if (argc == 2)
		arr = parse_input(argv, arr);
	i = arr_len(arr);
	if (i == 1)
		return (0);
	if (!is_valid_input(arr, i, 0))
	{
		free_arr(arr);
		for_error(NULL, NULL);
		exit(1);
	}
	mas = make_mas(arr, i);
	a = make_stack(mas, i - 1, 1, 0);
	b = make_stack(NULL, 0, 2, 0);
	push_swap2(a, b, arr, mas);
	return (0);
}
