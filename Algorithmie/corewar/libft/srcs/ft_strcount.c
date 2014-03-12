/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 12:22:04 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 22:00:42 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of occurences of c (casted to a char)
** which were found on the string c
*/
size_t		ft_strcount(const char *s, int c)
{
	char	chr;
	size_t	count;

	if (c == 0)
		return (1);
	chr = (char)c;
	count = 0;
	while (*s != '\0')
	{
		if (*s == chr)
			count++;
		s++;
	}
	return (count);
}
