/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	conv_to_proc(t_lst *lst)
{
	char	*buf;
	char	*tmp;
	int		len;

	buf = "%";
	len = ft_strlen(buf);
	if (lst->width < len)
		tmp = ft_strnew(ft_strlen(buf));
	else
		tmp = ft_strnew(lst->width);
	if (lst->precision > 0 && len > lst->precision)
		tmp = ft_strncpy(tmp, buf, lst->precision);
	else
		tmp = ft_strcpy(tmp, buf);
	len = ft_strlen(tmp);
	if (lst->width > 0 && (len < lst->width))
		((lst->zero && !lst->min) ? make_width(&tmp, lst, '0', lst->width) :
		make_width(&tmp, lst, ' ', lst->width));
	lst->out = tmp;
}

void	make_out2(t_lst *lst, va_list *val)
{
	if (lst->type == 'f')
		conv_to_f(lst, val);
	else if (lst->type == '%')
		conv_to_proc(lst);
	else if (lst->type == 'U')
	{
		lst->type = 'u';
		lst->len = "l";
		conv_to_u(lst, val);
	}
}

void	make_out(t_lst *lst, va_list *val)
{
	if (!lst->type)
		lst->out = "";
	else if (lst->type == 's')
		conv_to_s(lst, val);
	else if (lst->type == 'c')
		conv_to_c(lst, val);
	else if (lst->type == 'p')
		conv_to_p(lst, val);
	else if (lst->type == 'i' || lst->type == 'd')
		conv_to_i(lst, val);
	else if (lst->type == 'u')
		conv_to_u(lst, val);
	else if (lst->type == 'o')
		conv_to_o(lst, val);
	else if (lst->type == 'x')
		conv_to_x(lst, val, 0);
	else if (lst->type == 'X')
		conv_to_x(lst, val, 1);
	else
		make_out2(lst, val);
}
