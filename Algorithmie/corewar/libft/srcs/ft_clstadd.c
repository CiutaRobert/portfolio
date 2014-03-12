/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 17:52:36 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/08 18:07:18 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clstadd(t_clist **alst, t_clist *new)
{
	t_clist		*old;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	old = *alst;
	new->size = old->size + 1;
	new->first->next = old->first;
	ft_clstclean(&new);
	*alst = new;
}
