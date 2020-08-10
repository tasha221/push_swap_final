/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:41:02 by amariett          #+#    #+#             */
/*   Updated: 2019/09/08 18:41:02 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		while (needle[i] && haystack[i] && haystack[i] == needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
