/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:26:27 by amariett          #+#    #+#             */
/*   Updated: 2020/02/01 19:26:29 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_list)
{
	int		i;
	t_list	*p;

	i = 0;
	p = begin_list;
	if (!begin_list)
		return (0);
	while (p->next)
	{
		i++;
		p = p->next;
	}
	return (i + 1);
}
