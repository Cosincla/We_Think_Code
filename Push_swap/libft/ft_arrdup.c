/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:15:45 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/27 15:23:54 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_arrdup(char **a1)
{
	char	**a2;
	int		i;

	i = 0;
	if (!(a2 = (char **)malloc(ft_arrlen(a1))))
		return (NULL);
	while (a1[i])
	{
		a2[i] = ft_strdup(a1[i]);
		i++;
	}
	a2[i] = (NULL);
	return (a2);
}
