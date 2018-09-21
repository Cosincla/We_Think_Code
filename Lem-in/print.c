/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 08:07:20 by cosincla          #+#    #+#             */
/*   Updated: 2018/09/19 14:53:54 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

char		*ft_firstelem(char *str)
{
	char	*ret;
	char	**temp;

	temp = ft_strsplit(str, ' ');
	ret = strdup(temp[0]);
	ft_carrdel(temp);
	return (ret);
}

void		ft_flags(t_data **data, char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "-m") == 0)
		{
			ft_putchar('\n');
			ft_putarr((*data)->matrix);
		}
		else if (ft_strcmp(argv[i], "-p") == 0)
		{
			ft_putchar('\n');
			ft_putarr((*data)->path);
		}
		i++;
	}
}

void		ft_printer(t_data **data)
{
	int		i;
	int		j;
	char	*ret;

	j = 1;
	ft_putarr((*data)->print);
	ft_putchar('\n');
	while (j <= (*data)->ants)
	{
		i = 1;
		while (i < (int)ft_arrlen((*data)->path))
		{
			ret = ft_firstelem((*data)->path[i]);
			ft_putchar('L');
			ft_putnbr(j);
			ft_putchar('-');
			ft_putendl(ret);
			free(ret);
			i++;
		}
		j++;
	}
}
