/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_to_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

double		ft_dtoa_adder(int prec)
{
	double	add;

	add = 0.05;
	while (prec-- > 1)
		add /= 10;
	return (add);
}

char		*make_resf(char *fp, char *sp)
{
	char	*res;

	if (!(res = ft_strnew(ft_strlen(fp) + ft_strlen(sp) + 2)))
		return (NULL);
	if (fp)
		ft_strcat(res, fp);
	ft_strcat(res, ".");
	if (sp)
		ft_strcat(res, sp);
	free(fp);
	free(sp);
	return (res);
}

char		*make_f(t_lst *lst, va_list *val)
{
	long long		fp;
	double			sp;
	char			*buf[2];
	int				i;
	double			num;

	num = va_arg(*val, double);
	fp = (long long)num;
	sp = (double)(num - fp) * (num < 0 ? -1 : 1);
	buf[0] = ft_lltoa(fp);
	i = 0;
	if (lst->precision > 0)
	{
		buf[1] = ft_strnew(0);
		sp += ft_dtoa_adder(lst->precision);
		while (i < lst->precision)
		{
			sp *= 10;
			buf[1][i++] = ((int)sp % 10) + '0';
		}
		buf[0] = make_resf(buf[0], buf[1]);
	}
	else if (lst->hash)
		ft_strcat(buf[0], ".");
	return (buf[0]);
}

char		*make_lf(t_lst *lst, va_list *val, int i)
{
	long long		fp;
	long double		sp;
	char			*buf[2];
	long double		num;

	num = va_arg(*val, long double);
	fp = (long long)num;
	sp = (long double)(num - fp) * (num < 0 ? -1 : 1);
	buf[0] = ft_lltoa(fp);
	if (lst->precision > 0)
	{
		buf[1] = ft_strnew(0);
		sp += ft_ldtoa_adder(lst->precision);
		while (i < lst->precision)
		{
			sp *= 10;
			buf[1][i++] = ((int)sp % 10) + '0';
			sp -= (int)(sp);
		}
		buf[0] = make_resf(buf[0], buf[1]);
	}
	else if (lst->hash)
		ft_strcat(buf[0], ".");
	return (buf[0]);
}

void		conv_to_f(t_lst *lst, va_list *val)
{
	char	*tmp;
	char	*res;
	int		len;

	if (lst->precision == -1)
		lst->precision = 6;
	if (ft_strequ(lst->len, "L"))
		tmp = make_lf(lst, val, 0);
	else
		tmp = make_f(lst, val);
	tmp = make_fl_f(tmp, lst);
	len = ft_strlen(tmp);
	if (len < lst->width)
	{
		res = ft_strnew(lst->width);
		res = ft_strcpy(res, tmp);
		make_width_f(&res, lst);
		lst->out = res;
		free(tmp);
	}
	else
		lst->out = tmp;
}
