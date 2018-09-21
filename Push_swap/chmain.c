/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:36:33 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/30 15:47:58 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int				ft_op(char *line, t_data *data)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(data, data->arra);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(data, data->arra, data->arrb);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(data, data->arra);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(data, data->arra);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(data, data->arrb);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(data, data->arra, data->arrb);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(data, data->arrb);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(data, data->arrb);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(data, data->arra, data->arrb);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(data, data->arra, data->arrb);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(data, data->arra, data->arrb);
	else
		return (0);
	return (1);
}

static int		ft_rest(t_data *data)
{
	char		*line;

	if (ft_line(data) == 0)
		return (0);
	while (get_next_line(0, &line))
	{
		if (ft_op(line, data) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
	}
	free(line);
	if ((ft_acheck(data, data->arra) < data->al) || data->blen > 0)
		ft_putendl("KO");
	else
		ft_putendl("OK");
	return (1);
}

static char		*ft_str(int argc, char **argv)
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

static int		function(char *str, t_data *data)
{
	if (ft_array(str, data) == 1)
	{
		if (ft_rest(data) == 0)
		{
			ft_putendl_fd("Error", 2);
			ft_freestruct(data);
			ft_strdel(&str);
			return (0);
		}
		ft_strdel(&str);
		ft_freestruct(data);
	}
	else
	{
		ft_putendl_fd("Error", 2);
		ft_strdel(&str);
		free(data);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_data		*data;
	char		*str;

	if (argc < 2)
		return (0);
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (0);
	str = ft_str(argc, argv);
	return (function(str, data));
}
