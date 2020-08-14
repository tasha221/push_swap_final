/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:39:27 by amariett          #+#    #+#             */
/*   Updated: 2019/09/26 17:12:05 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*sr;
	unsigned char	*ds;
	unsigned char	ch;

	ch = (unsigned char)c;
	sr = (unsigned char *)src;
	ds = (unsigned char *)dest;
	while (n != 0)
	{
		*ds = *sr;
		if (*sr == ch)
			return (ds + 1);
		++ds;
		++sr;
		--n;
	}
	return (NULL);
}
