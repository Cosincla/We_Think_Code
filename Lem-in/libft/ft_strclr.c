/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:17:26 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/21 10:36:33 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		i;

	i = 0;
	if (!(s))
		return ;
	while (s[i] != '\0')
	{
		s[i] = '\0';
		i++;
	}
}
