/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2019/09/26 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
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
		if ((res > 922337203685477580) || (res == 922337203685477580 &&
					str[i] >= '7' && str[i] <= '9'))
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		res = (res * 10) + str[i++] - '0';
	}
	return ((int)(res * sign));
}
