/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoau.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

size_t	len_numu(unsigned long long int n)
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

char	*ft_itoau(unsigned long long n, int size)
{
	char	*res;
	size_t	len;

	len = len_numu(n);
	res = ft_strnew(size);
	if (!res)
		return (NULL);
	while (len)
	{
		len--;
		res[len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}

char	*ft_itoabase8(unsigned long long int n, int size, int base, int upper)
{
	char	*res;
	size_t	len;
	char	*str;

	if (n == 0)
		return (ft_strdup("0\0\0"));
	len = len_num(n, base);
	res = ft_strnew(size);
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
	return (res);
}

size_t	len_numl(long long n)
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

char	*ft_lltoa(long long n)
{
	char	*res;
	int		sign;
	size_t	len;

	sign = 1;
	len = len_numl(n);
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
