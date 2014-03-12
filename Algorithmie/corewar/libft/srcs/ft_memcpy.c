/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:43:36 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 21:39:25 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Copy n bytes from memory area s2 to memory area s1.
** - If s1 and s2 overlap, behavior is undefined.
** - It returns the original value of s1.
*/
void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*dst;
	const char	*src;

	dst = (char*)s1;
	src = (const char*)s2;
	while (n--)
		*dst++ = *src++;
	return (s1);
}
