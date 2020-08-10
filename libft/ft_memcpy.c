/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:39:43 by amariett          #+#    #+#             */
/*   Updated: 2019/09/23 19:01:30 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*tmp;

	if (!dest && !src)
		return (NULL);
	tmp = dest;
	while (n)
	{
		*(char *)dest++ = *(char *)src++;
		n--;
	}
	return (tmp);
}
