/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:50:22 by amariett          #+#    #+#             */
/*   Updated: 2020/02/04 11:05:28 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **begin_list)
{
	t_list	*prev;
	t_list	*tmp;

	if (!begin_list)
		return ;
	if (!(*begin_list))
		return ;
	prev = 0;
	while ((*begin_list)->next)
	{
		tmp = (*begin_list)->next;
		(*begin_list)->next = prev;
		prev = (*begin_list);
		(*begin_list) = tmp;
	}
	(*begin_list)->next = prev;
}
