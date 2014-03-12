/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:17:30 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 17:06:40 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Duplicate an array of null terminated strings into a NULL terminated array.
** If the given size is negative, it is assumed that the oroginal array is NULL
** terminated, and ft_arrlen() is then used to get array size.
** If the new array or one of its elements could not be malloc'ed,
** NULL is returned, otherwise the new array is returned.
*/
char		**ft_strarrdup(char **array, int size)
{
	char	**new;
	int		i;

	if (array == NULL)
		return (NULL);
	if (size < 0)
		size = ft_arrlen((const void**)array);
	if ((new = (char**)ft_calloc((size + 1) * sizeof(char*))) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if ((new[i] = ft_strdup(array[i])) == NULL)
			return (NULL);
		i++;
	}
	new[i] = NULL;
	return (new);
}
