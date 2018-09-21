/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funca.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:28:08 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/28 15:54:10 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void		ft_sa(t_data *data, int *a)
{
	int		temp;

	if (data->alen > 1)
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
	}
	return ;
}

void		ft_pa(t_data *data, int *a, int *b)
{
	int		temp;

	if (data->blen > 0)
	{
		data->alen++;
		ft_rra(data, a);
		temp = a[0];
		a[0] = b[0];
		b[0] = temp;
		ft_rb(data, b);
		data->blen--;
	}
	return ;
}

void		ft_rra(t_data *data, int *a)
{
	int		i;
	int		temp;

	i = data->alen - 1;
	while (i > 0)
	{
		temp = a[i];
		a[i] = a[(i - 1)];
		a[(i - 1)] = temp;
		i--;
	}
}

void		ft_ra(t_data *data, int *a)
{
	int		i;
	int		temp;

	i = 0;
	while (i < data->alen - 1)
	{
		temp = a[i];
		a[i] = a[(i + 1)];
		a[(i + 1)] = temp;
		i++;
	}
}

int			ft_acheck(t_data *data, int *a)
{
	int		i;

	i = 0;
	while (i < data->alen - 1)
	{
		if (a[i] > a[(i + 1)])
			break ;
		i++;
	}
	return (i);
}
