/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 00:47:07 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/21 01:03:06 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itobase(unsigned int value, int radix)
{
	char	*buf;
	int		b;
	int		mod;

	buf = ft_strnew(32);
	if (value == 0)
	{
		buf[0] = '0';
		return (buf);
	}
	b = 0;
	while (value)
	{
		mod = value % radix;
		value /= radix;
		buf[b++] = ((mod >= 0 && mod <= 9) ? (mod + 48) : (mod + 87));
	}
	ft_memrev(buf, b);
	return (buf);
}
