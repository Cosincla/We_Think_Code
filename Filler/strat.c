/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 09:11:25 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/16 15:54:21 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	ft_topleft(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->ymax)
	{
		x = 0;
		while (x < data->xmax)
		{
			if (ft_placechecker(data, x, y))
			{
				data->mx = x - data->pxstart;
				data->my = y - data->pystart;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_topright(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->ymax)
	{
		x = data->xmax - 1;
		while (x >= 0)
		{
			if (ft_placechecker(data, x, y))
			{
				data->mx = x - data->pxstart;
				data->my = y - data->pystart;
				return ;
			}
			x--;
		}
		y++;
	}
}

void	ft_bottomleft(t_data *data)
{
	int		y;
	int		x;

	y = data->ymax - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->xmax)
		{
			if (ft_placechecker(data, x, y))
			{
				data->mx = x - data->pxstart;
				data->my = y - data->pystart;
				return ;
			}
			x++;
		}
		y--;
	}
}

void	ft_bottomright(t_data *data)
{
	int		y;
	int		x;

	y = data->ymax - 1;
	while (y >= 0)
	{
		x = data->xmax - 1;
		while (x >= 0)
		{
			if (ft_placechecker(data, x, y))
			{
				data->mx = x - data->pxstart;
				data->my = y - data->pystart;
				return ;
			}
			x--;
		}
		y--;
	}
}

void	ft_setup(t_data *data)
{
	data->my = 0;
	data->mx = 0;
	data->px = 0;
	data->py = 0;
	data->ex = 0;
	data->ey = 0;
}
