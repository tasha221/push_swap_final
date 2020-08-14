/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:03:59 by amariett          #+#    #+#             */
/*   Updated: 2020/02/01 18:19:29 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		dop_del(void *content, size_t content_size)
{
	if (content_size != 0)
		free(content);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*beg;
	t_list	*cur;

	beg = NULL;
	if (f != NULL && lst != NULL)
	{
		beg = f(lst);
		cur = beg;
		lst = lst->next;
		while (lst != NULL)
		{
			if (cur == NULL)
			{
				ft_lstdel(&beg, dop_del);
				break ;
			}
			cur->next = f(lst);
			cur = cur->next;
			lst = lst->next;
		}
	}
	return (beg);
}
