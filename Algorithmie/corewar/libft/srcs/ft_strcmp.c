/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:46:38 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 21:59:26 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - The ft_strcmp() function lexicographically compare the null-terminated
**   strings s1 and s2.
** - It returns an integer greater than, equal to, or less than 0, according
**   as the string s1 is greater than, equal to, or less than the string s2.
**   The comparison is done using unsigned characters, so that `\200' is
**   greater than `\0'.
*/
int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((int)(*s1 - *s2));
}
