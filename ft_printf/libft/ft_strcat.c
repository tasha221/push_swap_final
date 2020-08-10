/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:39:59 by amariett          #+#    #+#             */
/*   Updated: 2019/09/23 18:59:25 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	ft_strcpy(dest + ft_strlen(dest), src);
	return (dest);
}

void	ft_strcat2(char **dest, const char *src)
{
	char	*new;

	new = ft_strnew(ft_strlen(*dest) + ft_strlen(src));
	ft_strcpy(new, (*dest));
	free(*dest);
	ft_strcpy(new + ft_strlen(new), src);
	*dest = new;
}
