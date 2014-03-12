/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:01:49 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 18:46:01 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - The ft_strdup() function allocates sufficient memory for a copy of the
**   string s1, does the copy, and returns a pointer to it.
** - If insufficient memory is available, NULL is returned.
*/
char	*ft_strdup(const char *s1)
{
	char	*new;
	char	*ptr;

	new = ft_strnew(ft_strlen(s1));
	if (new == NULL)
		return (NULL);
	ptr = new;
	while (*s1 != '\0')
		*new++ = *s1++;
	return (ptr);
}
