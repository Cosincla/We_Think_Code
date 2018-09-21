/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 09:40:41 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/08 09:16:50 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*m;

	i = 0;
	m = (unsigned char *)s;
	while ((size_t)i < n)
	{
		if (m[i] == (unsigned char)c)
			return (&m[i]);
		i++;
	}
	return (NULL);
}
