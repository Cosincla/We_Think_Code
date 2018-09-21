/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 09:05:37 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/03 12:08:45 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>

void		ft_pcheck(int fd, t_data *data)
{
	char	*line;

	get_next_line(fd, &line);
	if (ft_strchr(line, '1'))
	{
		data->player = 'O';
		data->eplayer = 'X';
	}
	else
	{
		data->player = 'X';
		data->eplayer = 'O';
	}
	free(line);
}

void		ft_gridreader(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	if (!(data->grid = (char **)malloc(sizeof(char *) * data->ymax + 1)))
		return ;
	get_next_line(fd, &line);
	while (i < (data->ymax))
	{
		get_next_line(fd, &line);
		data->grid[i] = ft_strsub(line, 4, (data->xmax));
		i++;
	}
	data->grid[i] = NULL;
	get_next_line(fd, &line);
	ft_piece_size(line, data);
}

void		ft_mapsize(int fd, t_data *data)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	get_next_line(fd, &line);
	data->ymax = ft_atoi(line + 8);
	j = data->ymax;
	while (j /= 10)
		++i;
	data->xmax = ft_atoi(line + 9 + i);
	free(line);
}

void		ft_piecereader(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	if (!(data->piece = (char **)malloc(sizeof(char *) * data->ty + 1)))
		return ;
	while (i < (data->ty))
	{
		get_next_line(fd, &line);
		data->piece[i] = ft_strsub(line, 0, data->tx);
		i++;
	}
	data->piece[i] = NULL;
}

int			main(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	ft_pcheck(0, data);
	data->c = 1;
	while (1)
	{
		ft_setup(data);
		ft_mapsize(0, data);
		ft_gridreader(0, data);
		if (data->px == 0 && data->py == 0 && data->ex == 0 && data->ey == 0)
			ft_locator(data);
		ft_piecereader(0, data);
		ft_ytrim(data);
		ft_xtrim(data);
		ft_mapread(data);
		free(data->grid);
		free(data->piece);
		ft_place(data);
	}
	free(data);
	return (0);
}
