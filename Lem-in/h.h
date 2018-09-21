/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 08:15:13 by cosincla          #+#    #+#             */
/*   Updated: 2018/09/19 14:44:47 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_H
# define H_H
# include "./libft/includes/libft.h"

typedef struct		s_data
{
	int				ants;
	int				rc;
	char			*start;
	char			*end;
	char			**print;
	char			**rooms;
	char			**links;
	char			**matrix;
	char			**path;
}					t_data;

int					ft_mapread(t_data **data);
int					ft_sort(t_data **data);
int					ft_rooms(t_data **data);
int					ft_rc(char **arr);
int					ft_links(t_data **data);
int					ft_lc(char **arr);
int					ft_ncheck(char *str);
int					ft_sncheck(char *str);
int					ft_rcheck(char *str);
int					ft_cc(char **arr);
int					ft_ccheck(char *str);
int					ft_lcheck(char *str);
int					ft_ordercheck(t_data **data);
int					ft_sortr(t_data **data);
int					ft_vallink(char *link, t_data **data);
int					ft_linkf(char *room, char *links, t_data **data);
int					ft_darr(t_data **data);
int					ft_matrix(t_data **data, char ***arr);
int					ft_doublecheck(t_data **data);
int					ft_bt(char **arr, char *str);
int					ft_path(t_data **data, int y);
void				ft_printer(t_data **data);
void				ft_freestruct(t_data *data);
void				ft_stringswap(char **a, char **b);
void				ft_flags(t_data **data, char **argv);
char				*ft_firstelem(char *str);

#endif
