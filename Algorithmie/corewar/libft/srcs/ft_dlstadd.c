/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 18:19:52 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/08 17:10:59 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	new->prev = NULL;
	new->next = *alst;
	*alst = new;
}
