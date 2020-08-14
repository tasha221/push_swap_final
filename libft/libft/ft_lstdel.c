/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:43:51 by amariett          #+#    #+#             */
/*   Updated: 2020/02/01 18:15:26 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst != NULL && del != NULL)
	{
		while (*alst != NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			tmp = (*alst)->next;
			free(*alst);
			*alst = tmp;
		}
	}
}
