/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 09:51:37 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 15:54:16 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function runs through a linked list, removing the ones that must be.
** Each link's data is compared with data_ref through the cmp function;
** If comparison don't returns zero, the link is then removed with the del
** function (through libft's ft_lstdelone() function).
*/
void		ft_lstdelif(t_list **alst, void (*del)(void *, size_t),
		void *data_ref, int (*cmp)(void *, void *))
{
	t_list		*link;
	t_list		*next;

	while (*alst != NULL && cmp(data_ref, (*alst)->data) != 0)
	{
		next = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = next;
	}
	if (*alst == NULL)
		return ;
	link = *alst;
	while (link != NULL && link->next != NULL)
	{
		next = link->next;
		if (cmp(data_ref, next->data) != 0)
		{
			link->next = next->next;
			ft_lstdelone(&next, del);
		}
		else
			link = next;
	}
}
