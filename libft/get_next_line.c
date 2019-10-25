/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 12:41:01 by cosincla          #+#    #+#             */
/*   Updated: 2018/07/02 09:29:10 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_toend(char const *c)
{
	size_t			i;

	i = 0;
	while (c[i] != '\n' && c[i] != '\0')
		i++;
	return (i);
}

static	char		*ft_joinfree(char *c[1], const int fd)
{
	char			*tem;
	char			buff[BUFF_SIZE + 1];
	int				r;

	if (!(c[fd]))
		c[fd] = ft_strnew(0);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		if ((tem = ft_strjoin(c[fd], buff)) == NULL)
			return (NULL);
		free(c[fd]);
		c[fd] = tem;
		if (ft_strchr(buff, '\n') || r < BUFF_SIZE)
			break ;
	}
	return (c[fd]);
}

int					get_next_line(const int fd, char **line)
{
	static char		*c[1];
	char			*tem;
	int				r;

	if (!(line) || fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	if ((c[fd] = ft_joinfree(c, fd)) == NULL)
		return (-1);
	r = ft_toend(c[fd]);
	if ((*line = ft_strsub(c[fd], 0, r)) == NULL)
		return (-1);
	if (c[fd][0] == '\0')
		return (0);
	if ((tem = ft_strdup(c[fd] + r + (c[fd][r] == '\n'))) == NULL)
		return (-1);
	free(c[fd]);
	c[fd] = tem;
	return (1);
}
