/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 19:51:05 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/28 02:28:10 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** A malloc wrapper that calls the ft_xmalloc_call() function on each
** call, and the ft_xmalloc_fail() function if memory allocation fails.
*/
void			*ft_xmalloc(size_t size)
{
	void	*result;

	result = ft_xmalloc_catch(malloc(size));
	if (result == NULL)
		ft_xmalloc_error();
	return (result);
}
