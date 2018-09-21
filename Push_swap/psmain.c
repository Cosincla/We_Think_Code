/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:10:29 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/30 15:48:13 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void			ft_findminmax(t_data *data, int *a)
{
	int			i;

	i = 0;
	data->min = a[i];
	data->max = a[i];
	while (i < data->alen - 1)
	{
		if (a[i] < data->min)
			data->min = a[i];
		if (a[i] > data->max)
			data->max = a[i];
		i++;
	}
}

static int		ft_next(t_data *data)
{
	ft_line(data);
	data->arra1 = ft_iarrdup(data->arra, data->argc);
	data->arrb1 = ft_iarrdup(data->arrb, data->argc - 1);
	while (1)
	{
		ft_findminmax(data, data->arra1);
		if (ft_acheck(data, data->arra1) == data->al)
			return (0);
		else
			ft_ifelse1(data);
	}
	return (1);
}

static char		*ft_pstr(int argc, char **argv)
{
	int			i;
	char		*str;

	str = ft_strdup(argv[1]);
	i = 2;
	while (i < argc)
	{
		if (!(str = ft_maljoin(str, " ")))
			return (NULL);
		if (!(str = ft_maljoin(str, argv[i])))
			return (NULL);
		i++;
	}
	return (str);
}

int				main(int argc, char **argv)
{
	t_data		*data;
	char		*str;

	if (argc < 2)
		return (0);
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (0);
	str = ft_pstr(argc, argv);
	if (ft_array(str, data) == 1)
	{
		if (ft_next(data) == 0)
		{
			ft_freestruct1(data);
			ft_strdel(&str);
			return (0);
		}
		ft_freestruct1(data);
	}
	else
	{
		free(data);
		ft_strdel(&str);
	}
	return (0);
}
