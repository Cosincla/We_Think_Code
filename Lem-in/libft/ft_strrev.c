/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 08:23:15 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/19 08:51:33 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*r;

	i = 0;
	j = 0;
	if (!(r = (char *)malloc(strlen(str) + 1)))
		return (0);
	while (str[i] != '\0')
		i++;
	i--;
	while (i >= 0)
	{
		r[j] = str[i];
		i--;
		j++;
	}
	r[j] = '\0';
	return (r);
}
