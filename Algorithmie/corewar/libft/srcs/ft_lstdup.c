/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:39:14 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/09 17:24:49 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a fresh copy of the given linked list.
** Each link is duplicated and a pointer to the first link is returned.
** If any link duplication fails, a NULL pointer is returned
*/
t_list		*ft_lstdup(t_list *lst)
{
	t_list		*new;
	t_list		*begin;

	if (lst == NULL)
		return (NULL);
	new = ft_lstdupone(lst);
	if (new == NULL)
		return (NULL);
	begin = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new->next = ft_lstdupone(lst);
		new = new->next;
		if (new == NULL)
			return (NULL);
	}
	return (begin);
}
