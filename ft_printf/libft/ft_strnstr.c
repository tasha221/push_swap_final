/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:40:52 by amariett          #+#    #+#             */
/*   Updated: 2019/09/08 18:40:52 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int			i;
	const char	*tmp;

	if (*needle == '\0')
		return ((char *)haystack);
	tmp = haystack;
	while (*haystack)
	{
		i = 0;
		while (needle[i] && haystack[i] && haystack[i] == needle[i] &&
				(haystack + i - tmp) < (long)n)
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
