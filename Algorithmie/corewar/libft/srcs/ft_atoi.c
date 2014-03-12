/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:59:45 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 20:28:47 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_atoi() function converts the initial portion of the string pointed
** to by str to int representation.
*/
int		ft_atoi(const char *str)
{
	int		result;
	int		multiply;

	while ((*str > 8 && *str < 14) || (*str == ' '))
		str++;
	multiply = 1;
	if (*str == '-' || *str == '+')
		multiply = 44 - *str++;
	result = 0;
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (result * multiply);
}
