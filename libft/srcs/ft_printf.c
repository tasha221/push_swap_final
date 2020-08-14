/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_lst		*parse_add(char *s, t_lst *lst, va_list *val, size_t i)
{
	unsigned int		dop;
	const char			*types;
	size_t				len;

	types = "cspdioUuxXf%";
	len = ft_strlen(s);
	while (i < len && s[i] != 0)
	{
		dop = i;
		if (s[i] == '%')
		{
			i++;
			while (s[i] != 0 && !ft_strchr(types, s[i]) && s[i] != 'Z')
				i++;
			lst_add(&lst, lst_create(ft_strsub(s, dop, i - dop + 1), val));
		}
		else
		{
			while (s[i + 1] != 0 && s[i + 1] != '%')
				i++;
			lst_add(&lst, lst_create(ft_strsub(s, dop, i - dop + 1), val));
		}
		i++;
	}
	return (lst);
}

t_lst		*parse(char *s, va_list *val)
{
	size_t	len;
	t_lst	*lst;

	len = ft_strlen(s);
	lst = NULL;
	if (len > 0)
	{
		lst = parse_add(s, lst, val, 0);
	}
	return (lst);
}

void		free_lst(t_lst *lst)
{
	if (lst->out && ft_strcmp(lst->out, ""))
		free(lst->out);
	free(lst);
}

void		ft_putstr2(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		if (*s == -1)
			*s = 0;
		write(1, s++, 1);
	}
}

int			ft_printf(const char *str, ...)
{
	va_list		val;
	t_lst		*lst;
	t_lst		*tmp;
	int			res;

	if (!str)
		return (0);
	va_start(val, str);
	lst = parse((char*)str, (va_list *)val);
	va_end(val);
	res = 0;
	while (lst)
	{
		ft_putstr2(lst->out);
		res += ft_strlen(lst->out);
		if (lst->for_null)
			res++;
		tmp = lst;
		lst = lst->next;
		free_lst(tmp);
	}
	return (res);
}
