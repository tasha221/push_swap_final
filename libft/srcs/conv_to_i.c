/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	make_prec_i2(char **tmp, t_lst *lst, int len, int i)
{
	int		prec;

	if (lst->precision > len)
	{
		if (lst->plus || lst->space || (*tmp)[0] == '-')
			prec = lst->precision + 1;
		else
			prec = lst->precision;
	}
	else
		prec = len + 1;
	i = ft_strlen(*tmp);
	while (i > -1 && (*tmp)[i] != '-')
	{
		(*tmp)[prec] = (*tmp)[i];
		prec--;
		i--;
	}
	while (prec > -1 && (*tmp)[prec] != '-')
		(*tmp)[prec--] = '0';
	if ((lst->plus || lst->space)
		&& (*tmp)[0] != '-')
		(*tmp)[0] = (lst->plus ? '+' : ' ');
}

void	make_prec_i(char **tmp, t_lst *lst)
{
	int		len;

	len = ft_strlen(*tmp);
	if ((*tmp)[0] == '0' && lst->precision == 0)
		(*tmp) = "";
	else if ((lst->precision < len && !lst->space && !lst->plus) ||
	((lst->space || lst->plus) && (*tmp)[0] == '-' && lst->precision < len))
		return ;
	else
		make_prec_i2(tmp, lst, len, 0);
}

void	make_width_i(char **tmp, t_lst *lst, int i, int len)
{
	char	c;

	if (lst->precision != -1)
		make_width(tmp, lst, ' ', lst->width);
	else if (lst->zero && !lst->min && len < lst->width)
		make_width(tmp, lst, '0', lst->width);
	else if (len < lst->width)
		make_width(tmp, lst, ' ', lst->width);
	if ((ft_strchr((*tmp), '+') || ft_strchr((*tmp), '-')) && lst->zero &&
	lst->precision == -1)
	{
		while (((*tmp)[i] != '+' && (*tmp)[i] != '-'))
			i++;
		c = (*tmp)[i];
		(*tmp)[i] = '0';
		(*tmp)[0] = c;
	}
	if (lst->space && lst->zero && (*tmp)[0] == '0')
	{
		i = 1;
		(*tmp)[0] = ' ';
		while ((*tmp)[i] != ' ')
			i++;
		(*tmp)[i] = '0';
	}
}

void	make_len_i(t_lst *lst, long long *buf, va_list *val)
{
	if (ft_strequ(lst->len, "hh"))
		*buf = (signed char)va_arg(*val, int);
	else if (ft_strequ(lst->len, "ll"))
		*buf = va_arg(*val, long long);
	else if (ft_strequ(lst->len, "h"))
		*buf = (short)va_arg(*val, int);
	else if (ft_strequ(lst->len, "l"))
		*buf = va_arg(*val, long);
	else
		*buf = va_arg(*val, int);
}

void	conv_to_i(t_lst *lst, va_list *val)
{
	long long		buf;
	char			*tmp;
	int				len_num;

	make_len_i(lst, &buf, val);
	len_num = len_numlong(buf);
	if ((lst->precision > len_num) || (lst->width > len_num))
	{
		if (lst->precision > lst->width)
			tmp = ft_itoalong(buf, lst->precision + 2);
		else
			tmp = ft_itoalong(buf, lst->width + 1);
	}
	else
		tmp = ft_itoalong(buf, len_num + 1);
	len_num = ft_strlen(tmp);
	if (tmp[0] == '-')
		len_num--;
	if (lst->precision > len_num || lst->precision == 0 ||
		lst->space || lst->plus)
		make_prec_i(&tmp, lst);
	len_num = ft_strlen(tmp);
	if (lst->width > len_num || lst->plus)
		make_width_i(&tmp, lst, 0, ft_strlen(tmp));
	lst->out = tmp;
}
