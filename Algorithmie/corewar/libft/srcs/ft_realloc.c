/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 12:04:54 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 17:05:50 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (new_size == 0)
	{
		ft_memdel(&ptr);
		return (NULL);
	}
	new = ft_calloc(new_size);
	if (new == NULL)
		return (NULL);
	if (old_size == 0)
		return (new);
	if (new_size < old_size)
		old_size = new_size;
	ft_memcpy(new, ptr, old_size);
	ft_memdel(&ptr);
	return (new);
}
