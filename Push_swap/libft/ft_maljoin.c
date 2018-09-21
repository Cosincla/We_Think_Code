/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maljoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:55:31 by cosincla          #+#    #+#             */
/*   Updated: 2018/08/28 12:58:36 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_maljoin(char *s1, char const *s2)
{
	char    *ret;

	if (!(s1) || !(s2))
		return (NULL);
	if (!(ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ret[0] = '\0';
	ft_strcat(ret, s1);
	ft_strcat(ret, s2);
	ft_strdel(&s1);
	return (ret);
}
