/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 22:05:06 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/19 22:22:56 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>

char		*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char*)s;
	while (*tmp)
	{
		if (*tmp == c)
			return (tmp);
		++tmp;
	}
	if (c == 0 && *tmp == 0)
		return (tmp);
	return (NULL);
}

