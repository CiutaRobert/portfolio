/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:22:12 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/22 14:50:18 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>

void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char*)s1;
	tmp2 = (char*)s2;
	while (n--)
		*tmp1++ = *tmp2++;
	return (s1);
}
