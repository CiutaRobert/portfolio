/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinsep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 23:09:56 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/27 23:21:45 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinsep(const char *s1, const char *sep, const char *s2)
{
	char	*new;
	char	*ptr;

	new = ft_strnew(ft_strlen(s1) + ft_strlen(sep) + ft_strlen(s2));
	if (new == NULL)
		return (NULL);
	ptr = new;
	while (*s1 != '\0')
		*new++ = *s1++;
	while (*sep != '\0')
		*new++ = *sep++;
	while (*s2 != '\0')
		*new++ = *s2++;
	return (ptr);
}
