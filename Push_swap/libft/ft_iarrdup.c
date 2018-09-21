/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iarrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:26:43 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/28 08:53:32 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			*ft_iarrdup(int *a1, int size)
{
	int		*a2;
	int		i;

	i = 0;
	if (!(a2 = (int *)malloc(sizeof(int) * size)))
		return (0);
	while (i < size)
	{
		a2[i] = a1[i];
		i++;
	}
	return (a2);
}
