/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:57:29 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/25 14:30:14 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	if (s == NULL)
		return (NULL);
	tmp = (unsigned char *)s;
	while (n--)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		++tmp;
	}
	return (NULL);
}
