/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:54:36 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/16 11:58:40 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Copy bytes from string s2 to string s1.
** - If the character c (as converted to an unsigned char) occurs in the
**   string s2, the copy stops and a pointer to the byte after the copy
**   of c in the string s1 is returned.
** - Otherwise, n bytes are copied, and a NULL pointer is returned.
*/
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*src;

	if (s1 == NULL || s2 == NULL || n == 0)
		return (NULL);
	dst = (unsigned char*)s1;
	src = (const unsigned char*)s2;
	while (n)
	{
		*dst = *src;
		if (*src == (unsigned char)c)
			return ((void*)(dst + 1));
		dst++;
		src++;
		n--;
	}
	return (NULL);
}
