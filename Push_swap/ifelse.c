/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifelse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 08:25:14 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/30 12:25:33 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void		ft_ifelse2(t_data *data)
{
	if (ft_acheck(data, data->arra1) == (data->alen - 1)
			&& ft_bcheck(data, data->arrb1) == (data->blen - 1))
	{
		ft_putendl("pa");
		ft_pa(data, data->arra1, data->arrb1);
	}
	else if (((data->arra1[0] == data->min)
			|| (data->arra1[0] <= ((data->max + data->min + 1) / 2)))
			&& ((data->blen) <= ((data->al) / 2)
			&& ((data->alen - 1) > 2)
			&& (ft_acheck(data, data->arra1) != (data->alen - 1))))
	{
		ft_putendl("pb");
		ft_pb(data, data->arra1, data->arrb1);
	}
	else
		ft_ifelse3(data);
	return ;
}

void		ft_ifelse1(t_data *data)
{
	if ((data->arra1[0] > data->arra1[1]) && (data->arrb1[0] < data->arrb1[1])
			&& data->blen > 1 && data->alen > 1)
	{
		ft_putendl("ss");
		ft_ss(data, data->arra1, data->arrb1);
	}
	else if (data->arra1[0] > data->arra1[1] &&
			data->arra1[0] < data->arra1[data->alen - 1])
	{
		ft_putendl("sa");
		ft_sa(data, data->arra1);
	}
	else if (data->arrb1[0] < data->arrb1[1] &&
			data->arrb1[0] < data->arrb1[(data->blen - 1)] && data->blen > 1)
	{
		ft_putendl("sb");
		ft_sb(data, data->arrb1);
	}
	else
		ft_ifelse2(data);
	return ;
}

void		ft_ifelse4(t_data *data)
{
	if (data->arra1[0] > data->arra1[(data->alen - 1)]
			|| data->arra1[(data->alen - 1)] < data->arra1[(data->alen - 2)]
			|| data->arra1[(data->alen - 1)] == data->min
			|| data->arra1[(data->alen - 2)] == data->min)
	{
		ft_putendl("rra");
		ft_rra(data, data->arra1);
	}
	else if (((data->blen - 1) > 2
			&& (data->arrb1[0] > data->arrb1[(data->blen - 1)]
			|| data->arrb1[(data->blen - 1)] < data->arrb1[(data->blen - 2)]
			|| data->arrb1[(data->blen - 1)] == data->max
			|| data->arrb1[(data->blen - 2)] == data->max))
			&& ft_bcheck(data, data->arrb1) != (data->blen - 1)
			&& data->blen > 1)
	{
		ft_putendl("rrb");
		ft_rrb(data, data->arrb1);
	}
	return ;
}

void		ft_ifelse3(t_data *data)
{
	if (data->arra1[0] > data->arra1[1] || data->arra1[1] > data->arra[2]
			|| data->arra1[0] == data->max || data->arra1[2] == data->max)
	{
		ft_putendl("ra");
		ft_ra(data, data->arra1);
	}
	else if ((data->arrb1[0] > data->arrb1[1] || data->arrb1[1] > data->arrb[2]
			|| data->arrb1[0] == data->min || data->arrb1[2] == data->min)
			&& ft_bcheck(data, data->arrb1) != (data->blen - 1)
			&& (data->blen - 1 > 2))
	{
		ft_putendl("rb");
		ft_rb(data, data->arrb1);
	}
	else
		ft_ifelse4(data);
	return ;
}
