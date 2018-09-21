/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:27:20 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/30 11:46:41 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void		ft_sb(t_data *data, int *b)
{
	int		temp;

	if (data->blen > 1)
	{
		temp = b[0];
		b[0] = b[1];
		b[1] = temp;
	}
	return ;
}

void		ft_pb(t_data *data, int *a, int *b)
{
	int		temp;

	if (data->alen > 0)
	{
		data->blen++;
		ft_rrb(data, b);
		temp = b[0];
		b[0] = a[0];
		a[0] = temp;
		ft_ra(data, a);
		data->alen--;
	}
	return ;
}

void		ft_rrb(t_data *data, int *b)
{
	int		i;
	int		temp;

	i = data->blen - 1;
	while (i > 0)
	{
		temp = b[i];
		b[i] = b[(i - 1)];
		b[(i - 1)] = temp;
		i--;
	}
}

void		ft_rb(t_data *data, int *b)
{
	int		i;
	int		temp;

	i = 0;
	while (i + 1 < data->blen)
	{
		temp = b[i];
		b[i] = b[(i + 1)];
		b[(i + 1)] = temp;
		i++;
	}
}

int			ft_bcheck(t_data *data, int *b)
{
	int		i;

	i = 0;
	while (i < (data->blen - 1))
	{
		if (b[i] < b[(i + 1)])
			break ;
		i++;
	}
	return (i);
}
