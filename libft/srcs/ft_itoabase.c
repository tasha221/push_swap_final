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

#include "../includes/printf.h"

size_t		len_num(unsigned long long int n, int base)
{
	size_t len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

char		*ft_itoabase16(unsigned long long int n, int base, int upper)
{
	char	*res;
	size_t	len;
	char	*str;

	if (n == 0)
		return (ft_strdup("0\0\0"));
	len = len_num(n, base) + 2;
	res = ft_strnew(len);
	if (upper)
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (!res)
		return (NULL);
	while (len)
	{
		len--;
		res[len] = str[(n % base)];
		n /= base;
	}
	res[0] = '0';
	res[1] = 'x';
	return (res);
}

size_t		len_numlong(long long int n)
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

char		*ft_itoalong(long long int n, int size)
{
	char	*res;
	int		sign;
	size_t	len;

	sign = 1;
	len = len_numlong(n);
	res = ft_strnew(size);
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
