/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*make_new_str(char c, int width, char **tmp)
{
	char	*buf;
	int		i;

	buf = ft_strnew(width);
	i = 0;
	while (i < width)
	{
		buf[i] = c;
		i++;
	}
	ft_strcat(buf, (*tmp));
	return (buf);
}

void	make_width2(char **tmp, int width, char c)
{
	int		i;
	int		j;
	char	*buf;

	buf = ft_strnew(width);
	i = 0;
	j = ft_strlen(*tmp);
	while (i < (width - j))
		buf[i++] = c;
	ft_strcat(buf, (*tmp));
	free(*tmp);
	(*tmp) = buf;
}

void	make_width(char **tmp, t_lst *lst, char c, int width)
{
	int		i;

	if ((*tmp)[0] == 0)
	{
		(*tmp) = make_new_str(c, width, tmp);
		return ;
	}
	if (lst->min)
	{
		i = ft_strlen(*tmp);
		while (i < width)
		{
			if (lst->type == 's')
				(*tmp)[i] = ' ';
			else
				(*tmp)[i] = c;
			i++;
		}
		(*tmp)[i] = 0;
	}
	else
		make_width2(tmp, width, c);
}

void	conv_to_s(t_lst *lst, va_list *val)
{
	char	*buf;
	char	*tmp;
	int		len;

	buf = va_arg(*val, char*);
	if (!buf)
		buf = "(null)";
	len = ft_strlen(buf);
	if (lst->width < len)
		tmp = ft_strnew(ft_strlen(buf));
	else
		tmp = ft_strnew(lst->width);
	if (lst->precision >= 0 && len > lst->precision)
		tmp = ft_strncpy(tmp, buf, lst->precision);
	else
		tmp = ft_strcpy(tmp, buf);
	len = ft_strlen(tmp);
	if (lst->width > 0 && (len < lst->width))
		((lst->zero) ? make_width(&tmp, lst, '0', lst->width) :
		make_width(&tmp, lst, ' ', lst->width));
	lst->out = tmp;
}

void	conv_to_c(t_lst *lst, va_list *val)
{
	char	*buf;
	int		len;
	int		width;

	len = 2;
	if (lst->width > 1)
		len = lst->width;
	buf = ft_strnew(len);
	buf[0] = va_arg(*val, int);
	width = lst->width;
	if (buf[0] == 0)
	{
		buf[0] = -1;
		lst->for_null = 1;
	}
	if (lst->width > 0)
	{
		if (lst->zero)
			make_width(&buf, lst, '0', width);
		else
			make_width(&buf, lst, ' ', width);
	}
	lst->out = buf;
}
