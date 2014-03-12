/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 18:30:23 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/08 17:18:32 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist		*ft_clstnew(const void *data, size_t size)
{
	t_clist		*clst;
	t_dlist		*lnk;

	clst = (t_clist*)ft_xmalloc(sizeof(t_clist));
	lnk = ft_dlstnew(data, size);
	lnk->prev = lnk;
	lnk->next = lnk;
	clst->first = lnk;
	clst->last = lnk;
	clst->size = 1;
	return (clst);
}
