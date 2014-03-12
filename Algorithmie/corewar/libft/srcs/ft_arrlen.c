/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 12:05:42 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/20 17:42:13 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns length of the given null terminated array of pointers.
*/
size_t		ft_arrlen(const void **array)
{
	size_t		len;

	len = 0;
	while (*array++ != NULL)
		len++;
	return (len);
}
