/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**argvdup(int argc, char **argv)
{
	char	**res;
	int		i;

	i = 0;
	res = (char **)malloc(sizeof(char*) * (argc + 1));
	while (i < argc)
	{
		res[i] = ft_strdup(argv[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

char	**parse_input(char **argv, char **arr)
{
	char		*buf;
	int			i;

	buf = ft_strnew(0);
	ft_strcat2(&buf, argv[0]);
	ft_strcat2(&buf, " ");
	ft_strcat2(&buf, argv[1]);
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	i = 0;
	arr = ft_strsplit(buf, ' ');
	free(buf);
	return (arr);
}

int		arr_len(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
