/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 23:29:24 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 17:08:21 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*my_stralloc(char const *start_idx, char c)
{
	char		*new;
	char		*end_idx;
	size_t		len;

	while (*start_idx == c)
		start_idx++;
	end_idx = ft_strchr(start_idx, c);
	if (end_idx == NULL)
		end_idx = ft_strchr(start_idx, '\0');
	len = end_idx - start_idx;
	new = ft_strnew(len);
	if (new == NULL)
		return (NULL);
	return ((char*)ft_memcpy(new, start_idx, len));
}

static int		my_simplearray(char ***array, char *s)
{
	(*array)[0] = ft_strdup(s);
	if ((*array)[0][0] == '\0')
		(*array)[0] = NULL;
	(*array)[1] = NULL;
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	char	**array_ptr;

	array = (char**)ft_calloc(sizeof(array) * (ft_strcount(s, c) + 2));
	if (array == NULL)
		return (NULL);
	array_ptr = array;
	while (c != '\0' && c == *s)
		s++;
	if ((ft_strlen(s) == 0 || c == '\0') && my_simplearray(&array, (char*)s))
		return (array_ptr);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		*array = my_stralloc(s, c);
		if (*array == NULL)
			return (NULL);
		s += ft_strlen(*array);
		if (*array[0] != '\0')
			array++;
	}
	*array = NULL;
	return (array_ptr);
}
