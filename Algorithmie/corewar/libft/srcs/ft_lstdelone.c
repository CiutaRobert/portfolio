/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:45:41 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 15:54:37 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		default_deleter(void *data, size_t size)
{
	(void)size;
	ft_memdel(&data);
}

void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (del == NULL)
		del = default_deleter;
	if (*alst != NULL)
	{
		del((*alst)->data, (*alst)->size);
		ft_memdel((void**)alst);
	}
}
