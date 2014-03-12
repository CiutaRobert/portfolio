/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 10:30:16 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 22:12:40 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	char			*ptr;
	unsigned int	idx;

	new = ft_strdup(s);
	if (new == NULL)
		return (NULL);
	ptr = new;
	idx = 0;
	while (*new != '\0')
		*new++ = f(idx++, *s++);
	return (ptr);
}
