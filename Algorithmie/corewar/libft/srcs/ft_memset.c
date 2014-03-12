/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:30:55 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 18:58:43 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Write len bytes of value c (converted to an unsigned char) to the
**   byte string b.
** - The ft_memset() function returns its first argument.
*/
void	*ft_memset(void *b, int c, size_t len)
{
	char			*ptr;
	unsigned char	chr;

	ptr = (char*)b;
	chr = (unsigned char)c;
	while (len--)
		*ptr++ = chr;
	return (b);
}
