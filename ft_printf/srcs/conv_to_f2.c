/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_f2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

long double		ft_ldtoa_adder(int prec)
{
	long double	add;

	add = 0.05;
	while (prec-- > 1)
		add /= 10;
	return (add);
}

void			make_width0(char **tmp)
{
	int i;

	i = 0;
	if (ft_strchr((*tmp), '-'))
	{
		(*tmp)[0] = '-';
		i++;
	}
	while ((*tmp)[i] != '-' && !ft_isdigit((*tmp)[i]))
	{
		(*tmp)[i] = '0';
		i++;
	}
	if ((*tmp)[i] == '-')
		(*tmp)[i] = '0';
}

void			make_width_f(char **tmp, t_lst *lst)
{
	make_width(tmp, lst, ' ', lst->width);
	if (lst->zero)
		make_width0(tmp);
}

char			*make_fl_f(char *tmp, t_lst *lst)
{
	char	*buf;

	if ((lst->space || lst->plus) && tmp[0] != '-')
	{
		buf = ft_strnew(ft_strlen(tmp) + 2);
		if (lst->plus)
			buf[0] = '+';
		else
			buf[0] = ' ';
		ft_strcat(buf, tmp);
		free(tmp);
		return (buf);
	}
	return (tmp);
}
