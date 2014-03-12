/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:19:16 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 21:55:15 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - The ft_strcat() function append a copy of the null-terminated string s2
**   to the end of the null-terminated string s1, then add a terminating `\0'.
** - The string s1 must have sufficient space to hold the result.
** - The ft_strcat() and function return the pointer s1.
*/
char	*ft_strcat(char *s1, const char *s2)
{
	char	*s1_ptr;

	s1_ptr = s1;
	while (*s1 != '\0')
		s1++;
	while (*s2 != '\0')
		*s1++ = *s2++;
	*s1 = '\0';
	return (s1_ptr);
}
