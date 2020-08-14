/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:56:25 by amariett          #+#    #+#             */
/*   Updated: 2020/01/16 11:38:54 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->next = NULL;
		if (content != NULL && content_size != 0)
		{
			new->content_size = content_size;
			new->content = malloc(content_size);
			if (new->content != NULL)
				ft_memcpy(new->content, content, content_size);
			else
			{
				free(new);
				new = NULL;
			}
		}
		else
		{
			new->content = NULL;
			new->content_size = 0;
		}
	}
	return (new);
}
