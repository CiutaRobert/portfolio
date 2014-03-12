/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 02:14:34 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/21 02:14:35 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		my_uintlen(unsigned int n)
{
	unsigned int		len;

	len = 1;
	while (n >= 10 && len++)
		n = n / 10;
	return (len);
}

static char				*my_uint_to_str(char *str, unsigned int n)
{
	if (n >= 10)
	{
		str = my_uint_to_str(str, (n / 10));
		str[ft_strlen(str)] = (char)((n % 10) + '0');
		return (str);
	}
	str[ft_strlen(str)] = (char)(n + '0');
	return (str);
}

char					*ft_uitoa(unsigned int n)
{
	char	*result;

	result = ft_strnew(my_uintlen(n));
	return (my_uint_to_str(result, n));
}
