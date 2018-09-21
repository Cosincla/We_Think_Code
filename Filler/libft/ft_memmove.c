/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:24:43 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/06 09:50:55 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_back(unsigned char *d, unsigned char *s, size_t len)
{
	while (len > 0)
	{
		len--;
		d[len] = s[len];
	}
	return (d);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (src < dst)
		return (ft_back(d, s, len));
	else
	{
		i = 0;
		while ((size_t)i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
