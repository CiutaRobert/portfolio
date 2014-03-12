/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstclean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 17:25:32 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/08 19:08:25 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_clstclean(t_clist **alst)
{
	t_clist		*clst;
	t_dlist		*lnk;
	size_t		i;

	clst = *alst;
	lnk = clst->first;
	i = 1;
	while (i < clst->size)
	{
		lnk->next->prev = lnk;
		lnk = lnk->next;
		i++;
	}
	lnk->next = clst->first;
	clst->last = lnk;
	clst->first->prev = clst->last;
}
