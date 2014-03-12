/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 03:27:25 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/12 03:29:05 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_pathjoin(const char *s1, const char *s2)
{
	char	*new;
	char	*ptr;

	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	ptr = new;
	while (*s1 != '\0')
		*new++ = *s1++;
	*new++ = '/';
	while (*s2 != '\0')
		*new++ = *s2++;
	return (ptr);
}
