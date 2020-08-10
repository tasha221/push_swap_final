/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:02:40 by amariett          #+#    #+#             */
/*   Updated: 2019/09/26 20:34:09 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_w(char const *s, char c)
{
	int i;
	int len;
	int count;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		i++;
		len++;
	}
	i = 0;
	count = 0;
	while (i < len)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void		ft_copy1(char **arr, char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		(*arr)[i] = str[i];
		i++;
	}
	(*arr)[i] = '\0';
}

static char		**ft_clean(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	return (NULL);
}

static char		**init(int wcount)
{
	char	**words;

	words = (char**)malloc(sizeof(*words) * (wcount + 1));
	if (words != NULL)
		words[wcount] = NULL;
	return (words);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**arr;
	int		i;
	int		len_i;
	int		i_s;

	if (!str || !(arr = init(ft_count_w((char*)str, c))))
		return (NULL);
	i = 0;
	i_s = 0;
	while (i < ft_count_w((char*)str, c))
	{
		len_i = 0;
		while (str[i_s] != '\0' && str[i_s] == c)
			i_s++;
		while (str[i_s] != '\0' && str[i_s] != c)
		{
			i_s++;
			len_i++;
		}
		if (!(arr[i] = (char*)malloc(sizeof(char) * (len_i + 1))))
			return (ft_clean(arr, i));
		ft_copy1((arr + i), (char *)(str + i_s - len_i), len_i);
		i++;
	}
	return (arr);
}
