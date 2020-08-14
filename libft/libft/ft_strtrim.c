/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:57:03 by amariett          #+#    #+#             */
/*   Updated: 2019/09/23 18:08:31 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_wspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char			*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	size_t	len;
	size_t	beg;

	if (!s)
		return (NULL);
	i = 0;
	beg = 0;
	while (is_wspace(s[i++]))
		beg++;
	if (beg == ft_strlen(s))
		return (ft_strnew(0));
	len = ft_strlen(s);
	while (is_wspace(s[len - 1]))
		len--;
	res = ft_strnew(len - beg);
	if (!res)
		return (NULL);
	ft_strcpy(res, ft_strsub(s, (unsigned int)beg, len - beg));
	return (res);
}
