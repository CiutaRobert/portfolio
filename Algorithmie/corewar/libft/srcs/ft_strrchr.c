/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:25:20 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 22:27:48 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - The ft_strrchr() function locates the last occurrence of c
**   (converted to a char) in the string pointed to by s.
** - The terminating null character is considered to be part of the string;
**   therefore if c is `\0', the functions locate the terminating `\0'.
** - The ft_strrchr() function return a pointer to the located character,
**   or NULL if the character does not appear in the string.
*/
char	*ft_strrchr(const char *s, int c)
{
	char		chr;
	size_t		size;

	chr = (char)c;
	size = ft_strlen(s) + 1;
	s += size - 1;
	while (size > 0)
	{
		if (*s == chr)
			return ((char*)s);
		s--;
		size--;
	}
	return (NULL);
}
