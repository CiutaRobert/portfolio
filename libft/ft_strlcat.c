/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:41:54 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/21 17:50:24 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst[dst_len])
		++dst_len;
	src_len = 0;
	while (src[src_len])
		++src_len;
	if (size < dst_len)
		return (src_len + size);
	i = 0;
	while (dst_len + i < size - 1 && src[i])
    {
		dst[dst_len + i] = src[i];
		++i;
    }
	dst[dst_len + i] = 0;
	return (dst_len + src_len);
}
