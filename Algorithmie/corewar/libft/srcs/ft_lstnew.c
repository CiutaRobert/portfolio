/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 18:06:16 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 15:55:33 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *data, size_t size)
{
	t_list		*list;

	list = (t_list*)ft_xmalloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	if (data == NULL)
	{
		list->data = NULL;
		list->size = 0;
		list->next = NULL;
		return (list);
	}
	list->data = ft_memdup((void*)data, size);
	list->size = size;
	list->next = NULL;
	return (list);
}
