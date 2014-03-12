/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 19:28:12 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/08 19:39:05 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_clstpop(t_clist *clst, t_dlist *pop)
{
	if (clst->first == pop)
		clst->first = pop->next;
	if (clst->last == pop)
		clst->last = pop->prev;
	pop->prev->next = pop->next;
	pop->next->prev = pop->prev;
	clst->size--;
	return (pop);
}
