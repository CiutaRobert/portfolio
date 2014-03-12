/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:30:38 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 22:39:59 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - The ft_strstr() function locates the first occurrence of the
**   null-terminated string s2 in the null-terminated string s1.
** - If s2 is an empty string, s1 is returned; if s2 occurs nowhere in s1,
**   NULL is returned; otherwise a pointer to the first character of the
**   first occurrence of s2 is returned.
*/
char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		s2_len;

	if (*s2 == '\0')
		return ((char*)s1);
	s2_len = ft_strlen(s2);
	while (*s1 != '\0')
	{
		if (*s1 == *s2 && ft_strncmp(s1, s2, s2_len) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
