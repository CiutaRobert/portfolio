/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 17:04:01 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 17:04:11 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t size)
{
	void	*ptr;

	ptr = ft_xmalloc(size);
	if (ptr == NULL)
		return (NULL);
	return (ft_memset(ptr, 0, size));
}
