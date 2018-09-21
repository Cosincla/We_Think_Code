/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:15:31 by cosincla          #+#    #+#             */
/*   Updated: 2018/09/19 15:21:08 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int			ft_links(t_data **data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!((*data)->links = (char **)malloc(sizeof(char *)
					* (ft_lc((*data)->print) + 1))))
		return (0);
	while ((*data)->print[i])
	{
		if (ft_lcheck((*data)->print[i]) == 1)
		{
			(*data)->links[j] = ft_strdup((*data)->print[i]);
			j++;
		}
		i++;
	}
	(*data)->links[j] = NULL;
	return (1);
}

int			ft_rooms(t_data **data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!((*data)->rooms = (char **)malloc(sizeof(char *)
					* (ft_rc((*data)->print) + 1))))
		return (0);
	while ((*data)->print[i])
	{
		if (ft_rcheck((*data)->print[i]) == 1)
		{
			(*data)->rooms[j] = ft_strdup((*data)->print[i]);
			j++;
		}
		i++;
	}
	(*data)->rooms[j] = NULL;
	(*data)->rc = j + 1;
	if (ft_sortr(data) == 0 || ft_doublecheck(data) == 0)
		return (0);
	return (ft_links(data));
}

int			ft_sort(t_data **data)
{
	int		i;
	int		c;
	int		r;

	i = 0;
	if (ft_rc((*data)->print) == 0 || ft_lc((*data)->print) == 0
			|| ft_cc((*data)->print) == 0)
		return (0);
	c = ft_rc((*data)->print) + ft_lc((*data)->print) + ft_cc((*data)->print);
	r = ft_arrlen((*data)->print) - 1;
	if (c != r)
		return (0);
	else
	{
		while (ft_ccheck((*data)->print[i]) == 1)
			i++;
		if (ft_ncheck((*data)->print[i]) == 1)
			(*data)->ants = ft_atoi((*data)->print[i]);
		else
			return (0);
	}
	return (ft_rooms(data));
}

int			ft_mapread(t_data **data)
{
	char	*line;

	if (!((*data)->print = (char **)malloc(sizeof(char *))))
		exit(0);
	(*data)->print[0] = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strlen(line) == 0)
		{
			ft_strdel(&line);
			return (0);
		}
		(*data)->print = ft_arrjoin((*data)->print, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (ft_arrlen((*data)->print) == 0 || ft_ordercheck(data) == 0)
		return (0);
	return (ft_sort(data));
}

int			main(int argc, char **argv)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		exit(0);
	if (ft_mapread(&data) == 0 || ft_darr(&data) == 0)
	{
		ft_putendl_fd("Input Error", 2);
		exit(0);
	}
	if (!(data->path = (char **)malloc(sizeof(char *))))
		exit(0);
	data->path[0] = NULL;
	if (ft_path(&data, 0) == 0)
	{
		ft_putendl_fd("Path Error", 2);
		exit(0);
	}
	ft_printer(&data);
	if (argc > 1)
		ft_flags(&data, argv);
	exit(1);
}
