/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmem_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 17:31:52 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 17:38:23 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "xmem.h"

static t_xmem_link	*new_xmem_link(void *ptr, int tag)
{
	t_xmem_link		*xmem_link;

	if ((xmem_link = (t_xmem_link*)malloc(sizeof(t_xmem_link))) == NULL)
		return (NULL);
	xmem_link->ptr = ptr;
	xmem_link->tag = tag;
	return (xmem_link);
}

static void			xmem_free_tag(t_list **alst, int tag)
{
	t_list			*link;
	t_list			*next;

	while (*alst != NULL && ((t_xmem_link*)((*alst)->data))->tag == tag)
	{
		next = (*alst)->next;
		ft_lstdelone(alst, NULL);
		*alst = next;
	}
	link = (*alst);
	while (link != NULL && link->next != NULL)
	{
		next = link->next;
		if (((t_xmem_link*)(link->data))->tag == tag)
		{
			link->next = next->next;
			ft_lstdelone(&next, NULL);
		}
		else
			link = next;
	}
}

void				*xmem_core(int action, void *ptr, int tag)
{
	static t_list	*db = NULL;
	t_list			*lnk;

	if (action == XMEM_FREE_ALL)
		ft_lstdel(&db, NULL);
	if (action == XMEM_FREE_TAG && db)
		xmem_free_tag(&db, tag);
	if (action != XMEM_ALLOC)
		return (NULL);
	if ((lnk = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if ((lnk->data = new_xmem_link(ptr, tag)) == NULL)
		return (NULL);
	lnk->size = sizeof(*(lnk->data));
	lnk->next = NULL;
	ft_lstadd(&db, lnk);
	return (ptr);
}
