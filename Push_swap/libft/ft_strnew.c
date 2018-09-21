/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:35:12 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/27 12:06:46 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ret;

	if (!(ret = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(ret, '\0', size + 1);
	return (ret);
}
