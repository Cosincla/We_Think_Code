/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 07:08:26 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/21 10:55:45 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while ((haystack[i] == needle[j]) && (needle[j] != '\0'))
			{
				j++;
				i++;
			}
			if (j == (ft_strlen(needle)))
				return ((char*)&haystack[i - j]);
			else
				i = i - j + 1;
		}
		i++;
	}
	return (NULL);
}
