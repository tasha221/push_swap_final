/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*make_zero_o(char *s)
{
	char	*buf;
	int		len;

	if (s[0] == '0')
		return (s);
	len = ft_strlen(s);
	buf = ft_strnew(len + 1);
	buf[0] = '0';
	ft_strcat(buf, s);
	if (s[0] != 0)
		free(s);
	return (buf);
}

void	conv_to_o(t_lst *lst, va_list *val)
{
	unsigned long long	buf;
	char				*tmp;
	int					len_n;

	make_len_u(lst, &buf, val);
	len_n = len_num(buf, 8);
	if ((lst->precision > len_n) || (lst->width > len_n))
	{
		if (lst->precision > lst->width)
			tmp = ft_itoabase8(buf, lst->precision + 1, 8, 0);
		else
			tmp = ft_itoabase8(buf, lst->width + 1, 8, 0);
	}
	else
		tmp = ft_itoabase8(buf, len_n + 1, 8, 0);
	if (lst->precision > len_n || lst->precision == 0)
		make_prec_u(&tmp, lst);
	if (lst->hash)
		tmp = make_zero_o(tmp);
	len_n = ft_strlen(tmp);
	if (lst->width > len_n)
		make_width_i(&tmp, lst, 0, ft_strlen(tmp));
	lst->out = tmp;
}
