/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 18:16:27 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 15:56:38 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Duplicate size bytes from data into a fresh memory area.
** It returns a pointer to the duplicated data, or NULL if malloc fails.
*/
void	*ft_memdup(void *data, size_t size)
{
	void	*new;

	new = ft_xmalloc(size);
	if (new == NULL)
		return (NULL);
	return (ft_memcpy(new, data, size));
}
