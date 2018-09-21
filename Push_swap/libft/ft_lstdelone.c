/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 09:20:36 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/08 08:45:49 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alist, void (*del)(void *, size_t))
{
	if (!(*alist) || (!(del)))
		return ;
	del((*alist)->content, (*alist)->content_size);
	free(*alist);
	*alist = NULL;
}
