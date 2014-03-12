/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:11:42 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 22:19:07 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy at most n characters from s2 into s1. If s2 is less than n characters
** long, the remainder of s1 is filled with `\0' characters.
** Otherwise, s1 is not terminated.
*/
char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*dst_ptr;

	dst_ptr = s1;
	while (n-- > 0)
	{
		*s1++ = *s2;
		if (*s2 != '\0')
			s2++;
	}
	return (dst_ptr);
}
