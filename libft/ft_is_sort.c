/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:40:53 by amariett          #+#    #+#             */
/*   Updated: 2020/02/01 18:40:54 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int res1;
	int rev;

	i = 0;
	res1 = 0;
	rev = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			res1++;
		i++;
	}
	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			rev++;
		i++;
	}
	if (res1 == 0 || rev == 0)
		return (1);
	return (0);
}
