/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amariett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:09:03 by amariett          #+#    #+#             */
/*   Updated: 2019/10/29 15:12:26 by amariett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		*ft_strjoinfree(const char *s1, const char *s2)
{
	char *ret;

	ret = ft_strjoin(s1, s2);
	free((void*)s1);
	return (ret);
}

int			check_s(char **s, int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		size;

	if (!*s)
		*s = ft_strnew(0);
	if (!ft_strchr(s[fd], '\n'))
		while (1)
		{
			size = read(fd, buf, BUFF_SIZE);
			buf[size] = '\0';
			if (size < 1)
			{
				if (size < 0 || (size == 0 && *s[0] == '\0'))
				{
					free(*s);
					return (size < 0 ? -1 : 0);
				}
				if (!ft_strchr(s[fd], '\n'))
					ft_strncpy(buf + size, "\n\0", 2);
			}
			*s = ft_strjoinfree(*s, buf);
			if (ft_strchr(s[fd], '\n') || size == 0)
				break ;
		}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[10];
	size_t		len;
	int			check;
	char		*tmp;

	if (fd < 0 || fd > 10 || BUFF_SIZE < 1)
		return (-1);
	check = check_s(s + fd, fd);
	if (check < 1)
		return (check);
	len = ft_strchr(s[fd], '\n') - s[fd];
	*line = ft_strnew(len);
	ft_strncpy(*line, s[fd], len);
	tmp = ft_strnew(ft_strlen(*s) - len - 1);
	ft_strcpy(tmp, *s + len + 1);
	free(*s);
	*s = tmp;
	return (1);
}
