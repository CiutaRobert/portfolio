/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/20 21:32:26 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/20 21:33:22 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		my_longlen(long n)
{
	long		len;

	len = ((n >= 0) ? 1 : 2);
	n = ((n < 0) ? n : -n);
	while (n <= -10 && len++)
		n = (n / -10) * -1;
	return (len);
}

static char		*my_long_to_str(char *str, long n)
{
	if (n <= -10)
	{
		str = my_long_to_str(str, ((n / -10) * -1));
		str[ft_strlen(str)] = (char)(((n % -10) * -1) + '0');
		return (str);
	}
	str[ft_strlen(str)] = (char)(-n + '0');
	return (str);
}

char			*ft_ltoa(long n)
{
	char	*result;

	result = ft_strnew(my_longlen(n));
	if (n < 0)
		result = ft_strcat(result, "-");
	else
		n = -n;
	return (my_long_to_str(result, n));
}
