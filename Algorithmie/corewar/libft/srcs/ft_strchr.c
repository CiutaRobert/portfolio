/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:56:27 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 21:56:32 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - The ft_strchr() function locates the first occurrence of c
**   (converted to a char) in the string pointed to by s.
** - The terminating null character is considered to be part of the string;
**   therefore if c is `\0', the functions locate the terminating `\0'.
** - The ft_strchr() function return a pointer to the located character,
**   or NULL if the character does not appear in the string.
*/
char	*ft_strchr(const char *s, int c)
{
	char	chr;
	int		size;

	chr = (char)c;
	size = ft_strlen(s) + 1;
	while (size--)
	{
		if (*s == chr)
			return ((char*)s);
		s++;
	}
	return (NULL);
}
