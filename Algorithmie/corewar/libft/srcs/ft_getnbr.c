/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 17:41:02 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/10 06:05:00 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnbr(char **ptr, int *nbr)
{
	int		multiply;
	char	*str;

	str = *ptr;
	while ((*str > 8 && *str < 14) || (*str == ' '))
		str++;
	multiply = 1;
	if (*str == '-' || *str == '+')
		multiply = 44 - *str++;
	if (!ft_isdigit(*str))
		return (0);
	*nbr = 0;
	while (*str >= '0' && *str <= '9')
		*nbr = (*nbr * 10) + (*str++ - '0');
	*nbr *= multiply;
	*ptr = str;
	return (1);
}
