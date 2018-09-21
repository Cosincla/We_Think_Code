/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 08:48:54 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/30 13:49:31 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_H
# define H_H
# include "./libft/includes/libft.h"

typedef	struct		s_data
{
	char			**argv;
	int				argc;
	int				alen;
	int				*arra1;
	int				*arrb1;
	int				blen;
	int				al;
	int				*arra;
	int				*arrb;
	int				min;
	int				max;
}					t_data;
int					ft_acheck(t_data *data, int *a);
int					ft_bcheck(t_data *data, int *b);
int					ft_numcheck(char *a);
int					ft_doubcheck(t_data *data);
int					ft_array(char *str, t_data *data);
int					ft_op(char *line, t_data *data);
void				ft_freestruct(t_data *data);
void				ft_freestruct1(t_data *data);
void				ft_ifelse1(t_data *data);
void				ft_ifelse2(t_data *data);
void				ft_ifelse3(t_data *data);
void				ft_ifelse4(t_data *data);
void				ft_findminmax(t_data *data, int *a);
int					ft_line(t_data *data);
void				ft_sa(t_data *data, int *a);
void				ft_pa(t_data *data, int *a, int *b);
void				ft_ra(t_data *data, int *a);
void				ft_rra(t_data *data, int *a);
void				ft_sb(t_data *data, int *b);
void				ft_pb(t_data *data, int *a, int *b);
void				ft_rb(t_data *data, int *b);
void				ft_rrb(t_data *data, int *b);
void				ft_rr(t_data *data, int *a, int *b);
void				ft_rrr(t_data *data, int *a, int *b);
void				ft_ss(t_data *data, int *a, int *b);
size_t				ft_arrlen(char **arr);

#endif
