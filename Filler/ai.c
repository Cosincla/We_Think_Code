/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:20:35 by cosincla          #+#    #+#             */
/*   Updated: 2018/07/31 15:55:43 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdio.h>

int		ft_placechecker(t_data *data, int x, int y)
{
	if (x + (data->pxend - data->pxstart + 1) > data->xmax)
		return (0);
	if (y + (data->pyend - data->pystart + 1) > data->ymax)
		return (0);
	return (ft_letcheck(data, x, y));
}

int		ft_letcheck(t_data *data, int x, int y)
{
	int		i;
	int		j;
	int		c;

	j = 0;
	c = 0;
	while (j <= (data->pyend - data->pystart))
	{
		i = 0;
		while (i <= (data->pxend - data->pxstart))
		{
			if (data->grid[y + j][x + i] == data->player &&
					data->piece[data->pystart + j][data->pxstart + i] == '*')
				c++;
			if (data->grid[y + j][x + i] == data->eplayer &&
					data->piece[data->pystart + j][data->pxstart + i] == '*')
				return (0);
			i++;
		}
		j++;
	}
	if (c == 1)
		return (1);
	return (0);
}

void	ft_mapread(t_data *data)
{
	int		horz;

	horz = data->xmax + 1;
	if (horz % 2 != 0)
		horz--;
	if (data->player == 'X' && horz < 50)
		ft_carli(data);
	if (data->px < (horz / 2) && data->ex >= (horz / 2))
		ft_right(data);
	if (data->px >= (horz / 2) && data->ex < (horz / 2))
		ft_left(data);
	if (data->px < (horz / 2) && data->ex < (horz / 2))
		ft_vert(data);
	if (data->px >= (horz / 2) && data->ex >= (horz / 2))
		ft_vert(data);
}
