/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 10:19:55 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 22:11:33 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*ptr;

	new = ft_strdup(s);
	if (new == NULL)
		return (NULL);
	ptr = new;
	while (*new != '\0')
		*new++ = f(*s++);
	return (ptr);
}
