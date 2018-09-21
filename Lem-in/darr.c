/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:15:04 by cosincla          #+#    #+#             */
/*   Updated: 2018/09/19 14:33:29 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int			ft_vallink(char *link, t_data **data)
{
	int		i;

	i = 0;
	while (i < (int)ft_arrlen((*data)->rooms))
	{
		if (ft_strncmp(link, (*data)->rooms[i], ft_strlen((*data)->rooms[i])))
			return (1);
		i++;
	}
	return (0);
}

int			ft_linkf(char *room, char *links, t_data **data)
{
	char	**tempr;
	char	**templ;

	templ = ft_strsplit(links, '-');
	tempr = ft_strsplit(room, ' ');
	if (ft_strcmp(tempr[0], templ[0]) == 0 && ft_vallink(templ[1], data) == 1)
	{
		ft_carrdel(tempr);
		ft_carrdel(templ);
		return (1);
	}
	else if (ft_strcmp(tempr[0], templ[1]) == 0
			&& ft_vallink(templ[0], data) == 1)
	{
		ft_carrdel(tempr);
		ft_carrdel(templ);
		return (1);
	}
	else
	{
		ft_carrdel(tempr);
		ft_carrdel(templ);
		return (0);
	}
}

int			ft_darr(t_data **data)
{
	int		i;
	int		k;
	int		ref;
	char	***arr;

	i = -1;
	ref = ft_arrlen((*data)->rooms);
	if (!(arr = (char ***)malloc(sizeof(char **) * ref + 1)))
		return (0);
	while (++i < ref)
	{
		k = -1;
		if (!(arr[i] = (char **)malloc(sizeof(char *))))
			return (0);
		arr[i][0] = NULL;
		arr[i] = ft_arrjoin(arr[i], (*data)->rooms[i]);
		while (++k < (int)ft_arrlen((*data)->links))
		{
			if (ft_linkf((*data)->rooms[i], (*data)->links[k], data) == 1)
				arr[i] = ft_arrjoin(arr[i], (*data)->links[k]);
		}
	}
	arr[i] = NULL;
	return (ft_matrix(data, arr));
}

int			ft_doublecheck(t_data **data)
{
	int		i;
	int		j;
	char	**temp;
	char	**temp2;

	i = 0;
	while (i < (int)ft_arrlen((*data)->rooms) - 1)
	{
		j = i + 1;
		temp = ft_strsplit((*data)->rooms[i], ' ');
		while (j < (int)ft_arrlen((*data)->rooms))
		{
			temp2 = ft_strsplit((*data)->rooms[j], ' ');
			if (ft_strcmp(temp[0], temp2[0]) == 0)
				return (0);
			ft_carrdel(temp2);
			j++;
		}
		ft_carrdel(temp);
		i++;
	}
	return (1);
}

int			ft_path(t_data **data, int y)
{
	int		x;

	x = (*data)->rc - 1;
	(*data)->path = ft_arrjoin((*data)->path, (*data)->rooms[y]);
	if (ft_strcmp((*data)->end, (*data)->rooms[y]) == 0)
		return (1);
	while (x >= 0)
	{
		if ((*data)->matrix[y][x] == '1'
				&& ft_bt((*data)->path, (*data)->rooms[x]) == 1)
		{
			if (ft_path(data, x) == 1)
				return (1);
			else
				return (0);
		}
		x--;
	}
	return (0);
}
