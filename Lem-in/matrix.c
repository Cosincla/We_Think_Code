/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:35:42 by cosincla          #+#    #+#             */
/*   Updated: 2018/09/19 14:36:14 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int			ft_bt(char **arr, char *str)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_strsplit(str, ' ');
	while (arr[i])
	{
		if (ft_strncmp(arr[i], temp[0], ft_strlen(temp[0])) == 0)
		{
			ft_carrdel(temp);
			return (0);
		}
		i++;
	}
	ft_carrdel(temp);
	return (1);
}

int			ft_adj(char **arr1, char **arr2)
{
	int		i;
	int		j;

	i = 1;
	while (i < (int)ft_arrlen(arr1))
	{
		j = 1;
		while (j < (int)ft_arrlen(arr2))
		{
			if (ft_strcmp(arr1[i], arr2[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_matrix(t_data **data, char ***arr)
{
	int		i;
	int		j;

	i = -1;
	if (!((*data)->matrix = (char **)malloc(sizeof(char *) * (*data)->rc)))
		return (0);
	while (++i < (int)ft_arrlen((*data)->rooms))
	{
		j = -1;
		if (!((*data)->matrix[i] = (char *)malloc(sizeof(char) * (*data)->rc)))
			return (0);
		while (++j < (int)ft_arrlen((*data)->rooms))
		{
			if (i != j && ft_adj(arr[i], arr[j]) == 1)
				(*data)->matrix[i][j] = '1';
			else
				(*data)->matrix[i][j] = '0';
		}
		(*data)->matrix[i][j] = '\0';
	}
	(*data)->matrix[i] = NULL;
	ft_darrdel(arr);
	return (1);
}

int			ft_shrooms(t_data **data)
{
	int		i;
	int		j;

	i = 0;
	j = (*data)->rc - 2;
	while ((*data)->rooms[i])
	{
		if (ft_strcmp((*data)->rooms[i], (*data)->start) == 0 && i != 0)
			ft_stringswap(&(*data)->rooms[i], &(*data)->rooms[0]);
		else if (ft_strcmp((*data)->rooms[i], (*data)->end) == 0
				&& i != (j + 1))
			ft_stringswap(&(*data)->rooms[j], &(*data)->rooms[i]);
		i++;
	}
	return (1);
}

int			ft_sortr(t_data **data)
{
	int		i;

	i = 0;
	while ((*data)->print[i])
	{
		if (ft_sncheck((*data)->print[i]) == 1)
			(*data)->start = ft_strdup((*data)->print[++i]);
		else if (ft_sncheck((*data)->print[i]) == -1)
			(*data)->end = ft_strdup((*data)->print[++i]);
		i++;
	}
	return (ft_shrooms(data));
}
