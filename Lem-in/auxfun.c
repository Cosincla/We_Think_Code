/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:51:00 by cosincla          #+#    #+#             */
/*   Updated: 2018/09/19 14:18:08 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int			ft_rc(char **arr)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (arr[i])
	{
		if (ft_rcheck(arr[i]) == 1)
			ret++;
		i++;
	}
	return (ret);
}

int			ft_lc(char **arr)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (arr[i])
	{
		if (ft_lcheck(arr[i]) == 1)
			ret++;
		i++;
	}
	return (ret);
}

int			ft_cc(char **arr)
{
	int		i;
	int		s;
	int		e;
	int		ret;

	i = 0;
	s = 0;
	e = 0;
	ret = 0;
	while (arr[i])
	{
		if (ft_sncheck(arr[i]) == 1)
			s++;
		if (ft_sncheck(arr[i]) == -1)
			e++;
		if (ft_ccheck(arr[i]) == 1)
			ret++;
		i++;
	}
	if (s != 1 || e != 1)
		return (0);
	else
		return (ret);
}

int			ft_ordercheck(t_data **data)
{
	int		i;
	int		j;

	i = 1;
	while ((*data)->print[i])
	{
		if (ft_lcheck((*data)->print[i]) == 1)
		{
			j = i;
			while ((*data)->print[j + 1])
			{
				if (ft_rcheck((*data)->print[j]) == 1)
					return (0);
				if ((*data)->print[j] == NULL)
					break ;
				else
					j++;
			}
		}
		i++;
	}
	return (1);
}

void		ft_stringswap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
