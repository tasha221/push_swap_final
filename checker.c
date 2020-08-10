/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_both(char *buf, t_stack *a, t_stack *b, char **res)
{
	if (ft_strequ(buf, "ss"))
	{
		swap(a, res);
		swap(b, res);
	}
	else if (ft_strequ(buf, "rr"))
	{
		rotate(a, res);
		rotate(b, res);
	}
	else if (ft_strequ(buf, "rrr"))
	{
		rrotate(a, res);
		rrotate(b, res);
	}
}

int		apply_oper(char *buf, t_stack *a, t_stack *b, char **res)
{
	if (ft_strequ(buf, "sa"))
		swap(a, res);
	else if (ft_strequ(buf, "sb"))
		swap(b, res);
	else if (ft_strequ(buf, "pa"))
		push(a, b, res);
	else if (ft_strequ(buf, "pb"))
		push(b, a, res);
	else if (ft_strequ(buf, "ra"))
		rotate(a, res);
	else if (ft_strequ(buf, "rb"))
		rotate(b, res);
	else if (ft_strequ(buf, "rra"))
		rrotate(a, res);
	else if (ft_strequ(buf, "rrb"))
		rrotate(b, res);
	else if (ft_strequ(buf, "rrr") || ft_strequ(buf, "ss") ||
	ft_strequ(buf, "rr"))
		make_both(buf, a, b, res);
	else
	{
		for_error(a, b);
		return (0);
	}
	return (1);
}

int		check(t_stack *a, t_stack *b, int v, char **res)
{
	char	*buf;

	buf = 0;
	if (v)
		visual(a, b);
	while (get_next_line(0, &buf) == 1)
	{
		if (apply_oper(buf, a, b, res) == 0)
		{
			free(buf);
			return (0);
		}
		if (v)
			visual(a, b);
		free(buf);
	}
	return (1);
}

int		do_check(int i, char **arr, int v, char *res)
{
	t_stack		*a;
	t_stack		*b;
	int			*mas;

	if (!is_valid_input(arr, i, 1))
	{
		for_error(NULL, NULL);
		free(res);
		return (0);
	}
	mas = make_mas(arr, i);
	a = make_stack(mas, i - 1 - v, 1, 1);
	b = make_stack(NULL, 0, 2, 0);
	if (check(a, b, v, &res))
	{
		if (is_sorted(a, b))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_stack(a);
		free_stack(b);
	}
	free_arr(arr);
	free(res);
	return (0);
}

int		main(int argc, char **argv)
{
	int			v;
	char		*res;
	char		**arr;
	int			i;

	v = 0;
	i = 0;
	arr = argvdup(argc, argv);
	if (argc == 2)
		arr = parse_input(argv, arr);
	i = arr_len(arr);
	if (i == 1)
	{
		write(2, "Error\n", 6);
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
		return (0);
	}
	if (ft_strequ(arr[1], "-v"))
		v = 1;
	res = ft_strnew(0);
	do_check(i, arr, v, res);
}
