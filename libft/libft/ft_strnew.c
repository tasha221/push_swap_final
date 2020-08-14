/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:56:50 by amariett          #+#    #+#             */
/*   Updated: 2019/09/23 18:05:41 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	while (i <= size)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
