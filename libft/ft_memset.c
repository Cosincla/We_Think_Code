/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:05:25 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/06 11:24:43 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*u;

	i = 0;
	u = (unsigned char *)b;
	while ((size_t)i < len)
	{
		u[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
