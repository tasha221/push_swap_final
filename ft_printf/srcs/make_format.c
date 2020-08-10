/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		make_int(char *s, int i)
{
	char	*tmp;
	int		j;
	int		res;

	tmp = (char*)malloc(sizeof(char*) * 20);
	j = 0;
	while (ft_isdigit(s[i]))
	{
		tmp[j] = s[i];
		i++;
		j++;
	}
	tmp[j] = 0;
	res = ft_atoi(tmp);
	free(tmp);
	return (res);
}

int		make_len(char *s, int i, t_lst *lst)
{
	if (ft_strstr(s, "ll"))
		lst->len = "ll";
	else if ((ft_strstr(s, "l") && !ft_strequ(lst->len, "ll"))
			|| s[i] == 'j' || s[i] == 'z')
		lst->len = "l";
	else if (ft_strstr(s, "hh") && s[i + 1] == 'h')
		lst->len = "hh";
	else if (ft_strstr(s, "h") && !ft_strequ(lst->len, "hh"))
		lst->len = "h";
	else if (ft_strstr(s, "L"))
		lst->len = "L";
	if (lst->len)
		return (ft_strlen(lst->len));
	return (0);
}

void	make_flag(int i, char *s, t_lst *lst, int j)
{
	while (j < i)
	{
		if (s[j] == '0')
			lst->zero = 1;
		if (s[j] == '-')
			lst->min = 1;
		if (s[j] == '+')
			lst->plus = 1;
		if (s[j] == ' ')
			lst->space = 1;
		if (s[j] == '#')
			lst->hash = 1;
		j++;
	}
}

void	make_format2(char *s, int i, t_lst *lst, va_list *val)
{
	const char	*types;
	const char	*flags;

	flags = " +-#0";
	types = "cspdiouUxXf%";
	if (s[i] == '.')
		i = make_format_add(i, s, lst, val);
	if (ft_strchr(flags, s[i]))
		make_flag(i + 1, s, lst, i);
	if (!ft_strchr(types, s[i]))
		i += make_len(s, i, lst);
	while (s[i] && !ft_strchr(types, s[i]))
	{
		if (ft_strchr(flags, s[i]))
			make_flag(i + 1, s, lst, i);
		i++;
	}
	lst->type = ft_strchr(types, s[i])[0];
}

void	make_format(char *s, t_lst *lst, va_list *val)
{
	int			i;
	const char	*flags;

	flags = " +-#0";
	i = 1;
	if (ft_strchr(flags, s[i]))
	{
		while (ft_strchr(flags, s[i]))
			i++;
		make_flag(i, s, lst, 1);
	}
	if (ft_isdigit(s[i]))
	{
		lst->width = make_int(s, i);
		while (ft_isdigit(s[i]))
			i++;
	}
	else if (s[i] == '*')
	{
		lst->width = va_arg(*val, int);
		i++;
	}
	make_format2(s, i, lst, val);
}
