/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:41:42 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/06 13:25:08 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ret;

	if (!(size))
		return (NULL);
	if (!(ret = (char *)malloc(size)))
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
