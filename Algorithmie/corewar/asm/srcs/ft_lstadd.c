/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 18:01:01 by fflorens          #+#    #+#             */
/*   Updated: 2014/01/29 18:22:14 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		<corewar_asm.h>

static t_lstd	*ft_lstnew(void const *item)
{
	t_lstd		*out;

	if ((out = (t_lstd *) malloc(sizeof(t_lstd))) == NULL)
		return (NULL);
	out->content = (void *)item;
	out->prev = NULL;
	out->next = NULL;
	return (out);
}

void			ft_lstadd(t_lstd **alst, const void *item, t_order order)
{
	t_lstd		*node;
	t_lstd		*pos;

	pos = *alst;
	node = ft_lstnew(item);
	if (order == LIST_FRONT)
	{
		while (pos && pos->prev)
			pos = pos->prev;
		if (pos)
			pos->prev = node;
		node->next = pos;
		*alst = node;
	}
	else if (order == LIST_BACK)
	{
		while (pos && pos->next)
			pos = pos->next;
		if (pos)
			pos->next = node;
		node->prev = pos;
		if (!*alst)
			*alst = node;
	}
}
