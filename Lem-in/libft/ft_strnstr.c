/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:54:00 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/21 10:55:34 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			while ((haystack[i + j] == needle[j]) && needle[j] != '\0' &&
					i + j < len)
			{
				j++;
			}
			if (j == (ft_strlen(needle)))
				return ((char*)&haystack[i]);
			i++;
		}
		i++;
	}
	return (NULL);
}
