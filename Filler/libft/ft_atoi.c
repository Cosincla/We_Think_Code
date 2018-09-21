/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:31:11 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/21 08:56:36 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_signcheck(const char *str)
{
	int		i;
	int		sign;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	else if (str[i] == '+' || (str[i] >= '0' && str[i] <= '9'))
		sign = 1;
	else
		sign = 0;
	return (sign);
}

int			ft_atoi(const char *str)
{
	int		i;
	long	ret;
	int		sign;

	i = 0;
	ret = 0;
	sign = ft_signcheck(str);
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f') && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	if (sign == -1 && ret < 0)
		return (0);
	if (sign == 1 && ret < 0)
		return (-1);
	return (ret * sign);
}
