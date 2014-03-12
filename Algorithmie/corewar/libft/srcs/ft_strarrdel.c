/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 23:36:27 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/26 23:50:15 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function deletes an array of null terminated strings freeing each
** element and then the array pointer. If the given size if negative, it
** is assumed that the array is null terminated, and ft_arrlen() is then used
** to get array length. Otherwise, only size elements are deleted.
*/
void		ft_strarrdel(char **array, int size)
{
	int		i;

	i = 0;
	if (size < 0)
		size = ft_arrlen((const void**)array);
	while (i < size)
	{
		ft_memdel((void**)(array + i));
		i++;
	}
	ft_memdel((void**)(&array));
}
