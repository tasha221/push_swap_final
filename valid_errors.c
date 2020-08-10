/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			for_error(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}

long long		ft_atoll(const char *str)
{
	long long int	res;
	int				i;
	int				sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
		str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i++] - '0';
	}
	return ((res * sign));
}

int				is_int(char *s)
{
	int			len;
	long long	buf;

	len = ft_strlen(s);
	if ((s[0] == '-' && len < 11) || (s[0] != '-' && len < 10))
		return (1);
	if ((s[0] == '-' && len > 11) || (s[0] != '-' && len > 10))
		return (0);
	buf = ft_atoll(s);
	if (buf > 2147483647 || buf < -2147483648)
		return (0);
	return (1);
}

int				is_unique(char **av, int ac, int cur)
{
	int		i;
	int		fl;

	i = 1;
	fl = 0;
	if (ft_strequ(av[cur], "-0") || ft_strequ(av[cur], "0"))
		fl = 1;
	while (i < ac)
	{
		if (ft_strequ(av[cur], av[i]) && i != cur)
			return (0);
		else if ((ft_strequ(av[i], "0") || ft_strequ(av[i], "-0"))
		&& fl && i != cur)
			return (0);
		i++;
	}
	return (1);
}

int				is_valid_input(char **av, int ac, int check)
{
	int					buf;
	int					i;
	int					j;

	i = 1;
	if (check && ft_strequ(av[1], "-v"))
		i++;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (av[i][j])
			if (!ft_isdigit(av[i][j++]))
				return (0);
		if (j == 1 && av[i][0] == '-')
			return (0);
		if (!is_int(av[i]))
			return (0);
		buf = i - 1;
		if (!is_unique(av, ac, buf))
			return (0);
		i++;
	}
	return (1);
}
