/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:09:14 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/06 09:42:28 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	s = (char *)src;
	d = (char *)dst;
	while (i < n)
	{
		if (s[i] == (char)c)
		{
			i++;
			ft_memcpy(d, s, i);
			return (d + i);
		}
		i++;
	}
	ft_memcpy(dst, src, n);
	return (NULL);
}
