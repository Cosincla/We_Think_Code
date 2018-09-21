/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 09:13:59 by cosincla          #+#    #+#             */
/*   Updated: 2018/07/31 15:57:58 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>

void	ft_locator(t_data *data)
{
	int		i;
	int		j;

	j = 0;
	while (j < data->ymax)
	{
		i = 0;
		while (i < data->xmax)
		{
			if (data->grid[j][i] == data->player)
			{
				data->px = i;
				data->py = j;
			}
			if (data->grid[j][i] == data->eplayer)
			{
				data->ex = i;
				data->ey = j;
			}
			i++;
		}
		j++;
	}
}

void	ft_piece_size(char *line, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	data->ty = ft_atoi(line + 6);
	j = data->ty;
	while (j /= 10)
		++i;
	data->tx = ft_atoi(line + 7 + i);
	free(line);
}

void	ft_xtrim(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	data->pxstart = data->tx - 1;
	data->pxend = 0;
	while (i < data->ty)
	{
		j = 0;
		while (j < data->tx)
		{
			if (data->piece[i][j] == '*')
			{
				if (j >= data->pxend)
					data->pxend = j;
				if (j <= data->pxstart)
					data->pxstart = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_ytrim(t_data *data)
{
	int		i;
	int		j;

	j = 0;
	data->pystart = data->ty - 1;
	data->pyend = 0;
	while (j < data->tx)
	{
		i = 0;
		while (i < data->ty)
		{
			if (data->piece[i][j] == '*')
			{
				if (i <= data->pystart)
					data->pystart = i;
				if (i >= data->pyend)
					data->pyend = i;
			}
			i++;
		}
		j++;
	}
}
