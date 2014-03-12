/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 02:14:50 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/21 02:14:58 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	my_ulonglen(unsigned long n)
{
	unsigned long		len;

	len = 1;
	while (n >= 10 && len++)
		n = n / 10;
	return (len);
}

static char				*my_ulong_to_str(char *str, unsigned long n)
{
	if (n >= 10)
	{
		str = my_ulong_to_str(str, (n / 10));
		str[ft_strlen(str)] = (char)((n % 10) + '0');
		return (str);
	}
	str[ft_strlen(str)] = (char)(n + '0');
	return (str);
}

char					*ft_ultoa(unsigned long n)
{
	char	*result;

	result = ft_strnew(my_ulonglen(n));
	return (my_ulong_to_str(result, n));
}
