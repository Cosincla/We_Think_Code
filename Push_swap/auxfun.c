/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:06:44 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/28 15:47:41 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int			ft_line(t_data *data)
{
	int		i;

	i = 0;
	data->alen = data->argc;
	if (!(data->arra = (int *)malloc(sizeof(int) * data->argc)))
		return (0);
	while (i < data->alen)
	{
		data->arra[i] = ft_atoi(data->argv[i]);
		i++;
	}
	data->al = data->alen - 1;
	data->arra[i] = '\0';
	if (!(data->arrb = (int *)malloc(sizeof(int) * data->argc - 1)))
		return (0);
	i--;
	data->arrb[i] = '\0';
	while (i > 0)
	{
		i--;
		data->arrb[i] = 0;
	}
	data->blen = 0;
	return (1);
}

int			ft_doubcheck(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->argc - 1)
	{
		j = i + 1;
		while (j < data->argc)
		{
			if (ft_strcmp(data->argv[i], data->argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		ft_freestruct(t_data *data)
{
	ft_carrdel(data->argv);
	ft_iarrdel(&data->arra);
	ft_iarrdel(&data->arrb);
	free(data);
}

void		ft_freestruct1(t_data *data)
{
	ft_iarrdel(&data->arra1);
	ft_iarrdel(&data->arrb1);
	ft_freestruct(data);
}
