/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_format2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		make_format_add(int i, char *s, t_lst *lst, va_list *val)
{
	i++;
	if (ft_isdigit(s[i]))
	{
		lst->precision = make_int(s, i);
		while (ft_isdigit(s[i]))
			i++;
	}
	else if (s[i] == '*')
	{
		lst->precision = va_arg(*val, int);
		i++;
	}
	else
		lst->precision = 0;
	return (i);
}
