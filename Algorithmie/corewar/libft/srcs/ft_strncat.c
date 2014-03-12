/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:26:59 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/18 16:05:39 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - The ft_strncat() function append a copy of the null-terminated string s2
**   to the end of the null-terminated string s1, then add a terminating `\0'.
** - The string s1 must have sufficient space to hold the result.
** - The ft_strncat() function appends not more than n characters from s2,
**   and then adds a terminating `\0'.
** - The ft_strncat() and function return the pointer s1.
*/
char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s1_ptr;

	s1_ptr = s1;
	while (*s1 != '\0')
		s1++;
	while (*s2 != '\0' && n-- > 0)
		*s1++ = *s2++;
	*s1 = '\0';
	return (s1_ptr);
}
