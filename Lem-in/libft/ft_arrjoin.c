/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:17:29 by cosincla          #+#    #+#             */
/*   Updated: 2018/09/19 09:29:17 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_arrjoin(char **arr, char const *str)
{
	int			i;
	int			l;
	char		**ret;

	i = 0;
	l = ft_arrlen(arr) + 1;
	if (!(ret = (char **)malloc(sizeof(char *) * (l + 1))))
		return (NULL);
	while (arr[i] != NULL)
	{
		ret[i] = ft_strdup(arr[i]);
		i++;
	}
	ft_carrdel(arr);
	ret[i++] = ft_strdup(str);
	ret[i] = NULL;
	return (ret);
}
