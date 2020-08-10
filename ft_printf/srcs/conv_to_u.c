/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	make_prec_u2(char **tmp, t_lst *lst, int len, int prec)
{
	int		i;

	if (lst->precision > len)
		prec = lst->precision;
	else
		prec = len + 1;
	i = ft_strlen(*tmp);
	while (i > -1 && (*tmp)[i] != '-')
	{
		(*tmp)[prec] = (*tmp)[i];
		prec--;
		i--;
	}
	while (prec > -1)
	{
		(*tmp)[prec] = '0';
		prec--;
	}
}

void	make_prec_u(char **tmp, t_lst *lst)
{
	int		len;

	len = ft_strlen(*tmp);
	if ((*tmp)[0] == '0' && lst->precision == 0)
		(*tmp) = "";
	else if (lst->precision < len)
		return ;
	else
		make_prec_u2(tmp, lst, len, 0);
}

void	make_len_u(t_lst *lst, unsigned long long *buf, va_list *val)
{
	*buf = va_arg(*val, unsigned long long);
	if (ft_strequ(lst->len, "hh"))
		*buf = (unsigned char)(*buf);
	else if (ft_strequ(lst->len, "ll"))
		*buf = (unsigned long long)(*buf);
	else if (ft_strequ(lst->len, "h"))
		*buf = (unsigned short)(*buf);
	else if (ft_strequ(lst->len, "l"))
		*buf = (unsigned long)(*buf);
	else
		*buf = (unsigned int)(*buf);
}

void	conv_to_u(t_lst *lst, va_list *val)
{
	unsigned long long	buf;
	char				*tmp;
	int					len_num;

	make_len_u(lst, &buf, val);
	len_num = len_numu(buf);
	if ((lst->precision > len_num) || (lst->width > len_num))
	{
		if (lst->precision > lst->width)
			tmp = ft_itoau(buf, lst->precision + 1);
		else
			tmp = ft_itoau(buf, lst->width + 1);
	}
	else
		tmp = ft_itoau(buf, len_num + 1);
	len_num = ft_strlen(tmp);
	if (lst->precision > len_num || lst->precision == 0)
		make_prec_u(&tmp, lst);
	len_num = ft_strlen(tmp);
	if (lst->width > len_num)
		make_width_i(&tmp, lst, 0, ft_strlen(tmp));
	lst->out = tmp;
}
