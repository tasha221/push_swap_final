/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:38:14 by amariett          #+#    #+#             */
/*   Updated: 2020/08/04 20:29:57 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_lst	*lst_create_empty(t_lst *new, char *s)
{
	new->type = 0;
	new->precision = -1;
	new->width = -1;
	new->next = NULL;
	new->len = NULL;
	new->zero = 0;
	new->min = 0;
	new->hash = 0;
	new->plus = 0;
	new->space = 0;
	new->for_null = 0;
	if (!s)
		new->out = NULL;
	else
		new->out = s;
	return (new);
}

t_lst	*lst_create_format(t_lst *lst, char *s, va_list *val)
{
	size_t	len;
	char	*buf;

	len = ft_strlen(s);
	if (len < 2)
		return (NULL);
	if (s[1] == '%')
	{
		buf = ft_strnew(2);
		buf[0] = '%';
		free(s);
		return (lst_create_empty(lst, buf));
	}
	lst = lst_create_empty(lst, NULL);
	make_format(s, lst, val);
	make_out(lst, val);
	free(s);
	return (lst);
}

t_lst	*lst_create2(char *s, t_lst *new, va_list *val)
{
	int		len;
	char	*buf;

	len = ft_strlen(s);
	if (len == 1)
		new = lst_create_empty(new, "");
	else if (s[len - 1] != 'Z')
	{
		buf = ft_strnew(len);
		ft_strcpy(buf, s);
		new = lst_create_format(new, buf, val);
	}
	else
	{
		buf = ft_strnew(2);
		buf[0] = 'Z';
		new = (lst_create_empty(new, buf));
	}
	return (new);
}

t_lst	*lst_create(char *s, va_list *val)
{
	t_lst	*new;
	char	*buf;

	new = (t_lst*)malloc(sizeof(t_lst));
	if (s[0] != '%')
	{
		buf = ft_strnew(ft_strlen(s));
		ft_strcpy(buf, s);
		new = lst_create_empty(new, buf);
	}
	else
		new = lst_create2(s, new, val);
	free(s);
	return (new);
}

void	lst_add(t_lst **head, t_lst *new)
{
	t_lst	*tmp;

	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
}
