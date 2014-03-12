/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:39:19 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 22:24:22 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - The ft_strnstr() function locates the first occurrence of the
**   null-terminated string s2 in the string s1, where not more than
**   n characters are searched.
**   Characters that appear after a `\0' character are not searched.
** - If s2 is an empty string, s1 is returned; if s2 occurs nowhere in s1,
**   NULL is returned; otherwise a pointer to the first character of the
**   first occurrence of s2 is returned.
*/
char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		s2_len;

	if (*s2 == '\0')
		return ((char*)s1);
	s2_len = ft_strlen(s2);
	while (n > 0 && *s1 != '\0')
	{
		if (n < s2_len)
			return (NULL);
		if (*s1 == *s2 && ft_strncmp(s1, s2, s2_len) == 0)
			return ((char*)s1);
		s1++;
		n--;
	}
	return (NULL);
}
