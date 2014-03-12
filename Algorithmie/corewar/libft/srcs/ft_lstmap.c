/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:34:40 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/09 17:27:43 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*begin;

	if (lst == NULL)
		return (NULL);
	new = ft_lstdupone(f(lst));
	if (new == NULL)
		return (NULL);
	begin = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new->next = ft_lstdupone(f(lst));
		new = new->next;
		if (new == NULL)
			return (NULL);
	}
	return (begin);
}
