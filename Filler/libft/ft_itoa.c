/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:31:50 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/12 15:26:24 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_intlen(int n)
{
	int		i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		s;

	if (!n)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(ret = ft_strnew(ft_intlen(n))))
		return (NULL);
	s = ft_intlen(n) - 1;
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	while (n)
	{
		ret[s] = ((n % 10) + '0');
		n /= 10;
		s--;
	}
	return (ret);
}
