/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:20:12 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/21 10:59:35 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_arrcount(char const *s, char c)
{
	int i;
	int r;

	i = 0;
	r = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			r++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (r);
}

static	size_t	ft_arrlen(const char *s, char c, size_t i)
{
	size_t	j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		j++;
		i++;
	}
	return (j);
}

static	void	ft_freedom(char **str, int k)
{
	int		i;

	i = 0;
	while (i <= k - 1)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static	void	ft_return(char const *s, char c, char **ret)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			if (!(ret[k] = ft_strsub(s, i, ft_arrlen(s, c, i))))
			{
				ft_freedom(ret, k);
				ret = NULL;
				return ;
			}
			i += ft_arrlen(s, c, i);
			k++;
		}
		else
			i++;
	}
	ret[k] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;

	if (!(s))
		return (NULL);
	if (!(ret = (char **)malloc(sizeof(char *) * (ft_arrcount(s, c) + 1))))
		return (NULL);
	ft_return(s, c, ret);
	return (ret);
}
