/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:54:38 by amariett          #+#    #+#             */
/*   Updated: 2019/09/23 21:44:17 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		len_num(int n)
{
	size_t len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	char	*res;
	int		sign;
	size_t	len;

	sign = 1;
	len = len_num(n);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		sign = -1;
	}
	while (len)
	{
		if (sign == -1 && len == 1)
			break ;
		len--;
		res[len] = sign * (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
