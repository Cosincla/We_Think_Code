/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:32:35 by cosincla          #+#    #+#             */
/*   Updated: 2018/09/19 11:36:30 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnbr(char *str)
{
	char		*c;

	c = ft_itoa(ft_atoi(str));
	if (ft_strcmp(c, str) != 0)
		return (0);
	ft_strdel(&c);
	return (1);
}
