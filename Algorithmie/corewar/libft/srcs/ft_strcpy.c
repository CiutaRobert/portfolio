/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:08:43 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 22:01:31 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Copy the string s2 to s1 (including the terminating `\0' character).
** - The source and destination strings should not overlap,
**   as the behavior is undefined.
** - The function return s1.
*/
char	*ft_strcpy(char *s1, const char *s2)
{
	char	*s1_ptr;

	s1_ptr = s1;
	while (*s2 != '\0')
		*s1++ = *s2++;
	*s1 = '\0';
	return (s1_ptr);
}
