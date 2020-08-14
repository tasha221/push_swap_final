/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*make_fl_x(char *tmp, int up)
{
	char	*buf;
	int		i;

	i = 0;
	while (tmp[i] == '0')
		i++;
	if (!tmp[i])
		return (tmp);
	buf = ft_strnew(ft_strlen(tmp) + 2);
	buf[0] = '0';
	if (up)
		buf[1] = 'X';
	else
		buf[1] = 'x';
	ft_strcat(buf, tmp);
	free(tmp);
	return (buf);
}

void	make_width_x(t_lst *lst, char **tmp)
{
	if (lst->hash)
	{
		make_width(tmp, lst, ' ', lst->width);
		if (lst->zero && !lst->min && lst->precision == -1)
			make_zero(tmp);
	}
	else
		((lst->zero && lst->precision == -1) ?
			make_width(tmp, lst, '0', lst->width) :
		make_width(tmp, lst, ' ', lst->width));
}

void	conv_to_x(t_lst *lst, va_list *val, int up)
{
	unsigned long long	buf;
	char				*tmp;
	int					len_n;

	make_len_u(lst, &buf, val);
	len_n = len_num(buf, 16);
	if ((lst->precision > len_n) || (lst->width > len_n))
	{
		if (lst->precision > lst->width)
			tmp = ft_itoabase8(buf, lst->precision + 1, 16, up);
		else
			tmp = ft_itoabase8(buf, lst->width + 1, 16, up);
	}
	else
		tmp = ft_itoabase8(buf, len_n + 1, 16, up);
	if (lst->precision > len_n || lst->precision == 0)
		make_prec_u(&tmp, lst);
	if (lst->hash && tmp[0] != 0 && !ft_strequ(tmp, "0"))
		tmp = make_fl_x(tmp, up);
	len_n = ft_strlen(tmp);
	if (lst->width > len_n)
		make_width_x(lst, &tmp);
	lst->out = tmp;
}
