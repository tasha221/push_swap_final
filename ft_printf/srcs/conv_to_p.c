/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	make_zero(char **tmp)
{
	int i;

	i = 0;
	while ((*tmp)[i] != 'x')
	{
		if (i == 1)
			(*tmp)[i] = 'x';
		else
			(*tmp)[i] = '0';
		i++;
	}
	(*tmp)[i] = '0';
}

char	*make_prec_p(char *tmp, t_lst *lst)
{
	char	*buf;
	int		i;
	int		len;
	int		j;

	len = ft_strlen(tmp);
	if (len - 2 >= lst->precision)
		return (tmp);
	buf = ft_strnew(lst->precision + 2);
	buf[0] = '0';
	buf[1] = 'x';
	i = 2;
	while (i < (lst->precision + 2 - len + 2))
		buf[i++] = '0';
	j = 2;
	while (tmp[j])
	{
		buf[i] = tmp[j];
		i++;
		j++;
	}
	free(tmp);
	return (buf);
}

void	for_null(char **tmp, t_lst *lst)
{
	free(*tmp);
	if (lst->precision == 0)
	{
		(*tmp) = ft_strnew(3);
		ft_strcpy((*tmp), "0x");
	}
	else
	{
		(*tmp) = ft_strnew(4);
		ft_strcpy((*tmp), "0x0");
	}
}

void	conv_to_p(t_lst *lst, va_list *val)
{
	unsigned long int	buf;
	char				*res;
	char				*tmp;
	int					len;

	buf = va_arg(*val, unsigned long int);
	tmp = ft_itoabase16(buf, 16, 0);
	if (ft_strequ(tmp, "0"))
		for_null(&tmp, lst);
	tmp = make_prec_p(tmp, lst);
	len = ft_strlen(tmp);
	if (len < lst->width)
	{
		res = ft_strnew(lst->width);
		res = ft_strcpy(res, tmp);
		make_width(&res, lst, ' ', lst->width);
		if (lst->zero)
			make_zero(&res);
		lst->out = res;
		free(tmp);
	}
	else
		lst->out = tmp;
}
