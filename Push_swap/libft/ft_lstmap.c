/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosincla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:20:12 by cosincla          #+#    #+#             */
/*   Updated: 2018/06/07 13:35:45 by cosincla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;

	if (lst)
	{
		temp = ft_lstmap(lst->next, f);
		ft_lstadd(&temp, f(lst));
		return (temp);
	}
	return (NULL);
}
