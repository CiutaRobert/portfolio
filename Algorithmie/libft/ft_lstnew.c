/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 22:41:23 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/25 00:15:37 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	if ((elem = (t_list *)malloc(sizeof(*elem))) == NULL)
		return (NULL);
	if (content != NULL)
	{
		if ((elem->content = malloc(content_size)) == NULL)
			return (NULL);
		elem->content = ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	else
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	elem->next = NULL;
	return (elem);
}
