/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 08:59:20 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/04 10:16:19 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "../libft/includes/libft.h"

typedef struct		s_data
{
	int				ymax;
	int				xmax;
	int				py;
	int				px;
	int				pystart;
	int				pxstart;
	int				pyend;
	int				pxend;
	int				ey;
	int				ex;
	int				tx;
	int				ty;
	int				mx;
	int				my;
	int				c;
	char			player;
	char			eplayer;
	char			**grid;
	char			**piece;
}					t_data;
int					ft_placechecker(t_data *data, int x, int y);
int					ft_letcheck(t_data *data, int x, int y);
void				ft_mapread(t_data *data);
void				ft_vert(t_data *data);
void				ft_left(t_data *data);
void				ft_right(t_data *data);
void				ft_carli(t_data *data);
void				ft_pcheck(int fd, t_data *data);
void				ft_gridreader(int fd, t_data *data);
void				ft_piecereader(int fd, t_data *data);
void				ft_mapsize(int fd, t_data *data);
void				ft_locator(t_data *data);
void				ft_piece_size(char *line, t_data *data);
void				ft_xtrim(t_data *data);
void				ft_ytrim(t_data *data);
void				ft_topleft(t_data *data);
void				ft_topright(t_data *data);
void				ft_bottomleft(t_data *data);
void				ft_bottomright(t_data *data);
void				ft_place(t_data *data);
void				ft_setup(t_data *data);

#endif
