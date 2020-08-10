/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:54:43 by amariett          #+#    #+#             */
/*   Updated: 2019/09/21 16:09:32 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc(size);
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = 0;
		i++;
	}
	return ((void *)res);
}
