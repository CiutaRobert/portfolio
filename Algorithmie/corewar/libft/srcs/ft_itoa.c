/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:03:06 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 20:59:09 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		my_intlen(int n)
{
	int		len;

	len = ((n >= 0) ? 1 : 2);
	n = ((n < 0) ? n : -n);
	while (n <= -10 && len++)
		n = (n / -10) * -1;
	return (len);
}

static char		*my_int_to_str(char *str, int n)
{
	if (n <= -10)
	{
		str = my_int_to_str(str, ((n / -10) * -1));
		str[ft_strlen(str)] = (char)(((n % -10) * -1) + '0');
		return (str);
	}
	str[ft_strlen(str)] = (char)(-n + '0');
	return (str);
}

char			*ft_itoa(int n)
{
	char	*result;

	result = ft_strnew(my_intlen(n));
	if (n < 0)
		result = ft_strcat(result, "-");
	else
		n = -n;
	return (my_int_to_str(result, n));
}
