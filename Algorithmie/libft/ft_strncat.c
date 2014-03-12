/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:29:54 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/21 13:21:41 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>

char*		ft_strncat(char *s1, const char *s2, size_t n)
{
	int		len;
	size_t	i;

	len = 0;
	while (s1[len])
		++len;
	i = 0;
	while (i < n && s2[i])
    {
		s1[len + i] = s2[i];
		++i;
    }
	s1[len + i] = 0;
	return (s1);
}
