/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 21:26:25 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 15:53:49 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddsort(t_list **alst, t_list *new, int (*cmp)(void *, void *))
{
	t_list		*lst;

	if (*alst == NULL || cmp((*alst)->data, new->data) > 0)
		return (ft_lstadd(alst, new));
	lst = *alst;
	while (lst->next != NULL && cmp(lst->next->data, new->data) <= 0)
		lst = lst->next;
	new->next = lst->next;
	lst->next = new;
}
