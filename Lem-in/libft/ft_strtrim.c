/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:06:32 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/12 14:52:01 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_backtrim(char const *s)
{
	int		j;

	j = ft_strlen(s);
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n' || s[j] == '\0')
			&& j > 0)
		j--;
	return (j);
}

static int	ft_frontrim(char const *s)
{
	int		i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*ret;

	if (!(s))
		return (NULL);
	i = ft_frontrim(s);
	j = ft_backtrim(s);
	if (i > j)
		return (ft_strdup(""));
	ret = ft_strsub(s, i, (j - i + 1));
	return (ret);
}
