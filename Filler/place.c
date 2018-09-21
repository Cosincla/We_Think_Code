/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 08:24:35 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/03 11:49:05 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	ft_left(t_data *data)
{
		if ((data->c) % 2 == 0)
			ft_topleft(data);
		else
			ft_bottomleft(data);
		data->c++;
}

void	ft_right(t_data *data)
{
		if (data->c % 2 == 0)
			ft_bottomright(data);
		else
			ft_topright(data);
		data->c++;
}

void	ft_vert(t_data *data)
{
	if (data->py < data->ey)
	{
		if (data->c % 2 == 0)
			ft_bottomright(data);
		else
			ft_topleft(data);
		data->c++;
	}
	else
	{
		if (data->c % 2 == 0)
			ft_topright(data);
		else
			ft_bottomleft(data);
		data->c++;
	}
}

void	ft_carli(t_data *data)
{
	if (data->c % 3 == 0)
		ft_topright(data);
	else if (data->c % 2 == 0)
		ft_bottomright(data);
	else
		ft_topleft(data);
	data->c++;
}

void	ft_place(t_data *data)
{
	ft_putnbr(data->my);
	ft_putchar(' ');
	ft_putnbr(data->mx);
	ft_putchar('\n');
}
