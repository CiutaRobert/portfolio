/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:55:34 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/16 12:04:12 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Compare byte string s1 against byte string s2.
**   Both strings are assumed to be n bytes long.
** - The function returns zero if the two strings are identical, otherwise
**   returns the difference between the first two differing bytes
**   (treated as unsigned char values, so that `\200' is greater than
**   `\0', for example).  Zero-length strings are always identical.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*base;
	const unsigned char		*comp;

	if (s1 == NULL || s2 == NULL || n == 0)
		return (0);
	base = (const unsigned char*)s1;
	comp = (const unsigned char*)s2;
	while (n--)
	{
		if (*base != *comp)
			return ((int)(*base - *comp));
		base++;
		comp++;
	}
	return ((int)0);
}
