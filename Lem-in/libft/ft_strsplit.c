/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:20:12 by cosincla          #+#    #+#             */
/*   Updated: 2018/09/03 09:14:29 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_arrcount(char const *s, char c)
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

static	void	ft_freedom(char **str, int k)
{
	int		i;

	i = 0;
	while (i <= k - 1)
	{
		ft_strdel(&str[i]);
		i++;
	}
	ft_strdel(str);
}

static void		ft_return(char const *s, char c, char **ret)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (!(ret[k] = ft_strsub(s, j, (i - j))))
			{
				ft_freedom(ret, k);
				return ;
			}
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
