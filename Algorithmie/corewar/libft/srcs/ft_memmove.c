/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 23:20:43 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/16 11:55:49 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy n bytes from string s2 to string s1.  The two strings may overlap;
** the copy is always done in a non-destructive manner.
**
** - If no bytes have to be copied or source and destination point to the
**   same address, there is nothing to do.
** - If destination if shortest than source, there is no chance to overlap
**   so just return ft_memcpy result.
** - If desination is longest than source, start from the end, then decrement.
*/
void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*dst;
	const char	*src;

	if (s1 == NULL || s2 == NULL || s1 == s2 || n == 0)
		return (s1);
	dst = (char*)s1;
	src = (const char*)s2;
	if (src < dst && (src + n) > dst)
	{
		dst += n - 1;
		src += n - 1;
		while (n--)
			*dst-- = *src--;
	}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
