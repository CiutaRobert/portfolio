/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:44:13 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/16 11:53:24 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Locate the first occurrence of c (converted to an unsigned char)
**   in string s.
** - The function returns a pointer to the byte located, or NULL
**   if no such byte exists within n bytes.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ptr;

	ptr = (const unsigned char*)s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return ((void*)ptr);
		ptr++;
	}
	return (NULL);
}
