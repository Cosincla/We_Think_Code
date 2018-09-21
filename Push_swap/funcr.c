/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:26:02 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/28 15:40:41 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void		ft_ss(t_data *data, int *a, int *b)
{
	ft_sa(data, a);
	ft_sb(data, b);
}

void		ft_rr(t_data *data, int *a, int *b)
{
	ft_ra(data, a);
	ft_rb(data, b);
}

void		ft_rrr(t_data *data, int *a, int *b)
{
	ft_rra(data, a);
	ft_rrb(data, b);
}

int			ft_array(char *str, t_data *data)
{
	int		i;

	i = 0;
	data->argv = ft_strsplit(str, ' ');
	data->argc = ft_arrlen(data->argv);
	while (i < data->argc)
		i++;
	i = 0;
	while (i < data->argc)
	{
		if (ft_numcheck(data->argv[i]) == 0 || ft_doubcheck(data) == 0)
		{
			ft_carrdel(data->argv);
			return (0);
		}
		i++;
	}
	return (1);
}

int			ft_numcheck(char *a)
{
	int		i;
	char	*c;

	i = 0;
	c = ft_itoa(ft_atoi(a));
	if (ft_strcmp(a, c) != 0)
	{
		ft_strdel(&c);
		return (0);
	}
	while (a[i] != '\0')
	{
		if (i == 0 && a[i] == '-')
			i++;
		if (ft_isdigit(a[i]) == 0)
			return (0);
		i++;
	}
	ft_strdel(&c);
	return (1);
}
