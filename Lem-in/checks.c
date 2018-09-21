/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:26:47 by cosincla          #+#    #+#             */
/*   Updated: 2018/09/19 14:36:05 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int			ft_ncheck(char *str)
{
	if (ft_arrcount(str, ' ') != 1)
		return (0);
	if (ft_arrcount(str, '\t') != 1)
		return (0);
	if (ft_isnbr(str) != 1)
		return (0);
	if (ft_atoi(str) <= 0)
		return (0);
	return (1);
}

int			ft_sncheck(char *str)
{
	if (ft_strcmp(str, "##start") == 0)
		return (1);
	if (ft_strcmp(str, "##end") == 0)
		return (-1);
	else
		return (0);
}

int			ft_rcheck(char *str)
{
	int		i;
	char	**a;

	i = 1;
	if (!(a = ft_strsplit(str, ' ')))
		return (0);
	if (a[0][0] == 'L')
	{
		ft_carrdel(a);
		return (0);
	}
	if (ft_arrlen(a) == 3)
	{
		while (a[i])
		{
			if (ft_isnbr(a[i]) == 0)
			{
				ft_carrdel(a);
				return (0);
			}
			i++;
		}
	}
	else
	{
		ft_carrdel(a);
		return (0);
	}
	ft_carrdel(a);
	return (1);
}

int			ft_ccheck(char *str)
{
	if (str[0] == '#')
		return (1);
	else
		return (0);
}

int			ft_lcheck(char *str)
{
	int		i;
	char	**a;

	i = 0;
	if (!(a = ft_strsplit(str, '-')))
		return (0);
	if (ft_arrlen(a) != 2)
	{
		ft_carrdel(a);
		return (0);
	}
	if (ft_arrcount(&str[0], ' ') != 1 || ft_arrcount(&str[1], ' ') != 1
			|| ft_arrcount(&str[0], '\t') != 1
			|| ft_arrcount(&str[1], '\t') != 1)
	{
		ft_carrdel(a);
		return (0);
	}
	ft_carrdel(a);
	return (1);
}
