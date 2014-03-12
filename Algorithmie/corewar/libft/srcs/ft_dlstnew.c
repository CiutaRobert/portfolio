/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 18:13:13 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/08 17:10:01 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstnew(const void *data, size_t size)
{
	t_dlist		*lnk;

	if ((lnk = (t_dlist*)ft_xmalloc(sizeof(t_dlist))) == NULL)
		return (NULL);
	lnk->data = NULL;
	lnk->size = 0;
	if (data)
	{
		lnk->data = ft_memdup((void*)data, size);
		lnk->size = size;
	}
	lnk->prev = NULL;
	lnk->next = NULL;
	return (lnk);
}
