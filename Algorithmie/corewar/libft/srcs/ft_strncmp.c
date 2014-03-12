/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:56:12 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 22:14:58 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - The ft_strcmp() function lexicographically compare the null-terminated
**   strings s1 and s2. But not more than n characters.
** - Because it is designed for comparing strings rather than binary
**   data, characters that appear after a `\0' character are not compared.
** - It returns an integer greater than, equal to, or less than 0, according
**   as the string s1 is greater than, equal to, or less than the string s2.
**   The comparison is done using unsigned characters, so that `\200' is
**   greater than `\0'.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 1 && *s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return ((int)(*s1 - *s2));
}
