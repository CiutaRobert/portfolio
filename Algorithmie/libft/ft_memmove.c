/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:20:29 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/19 16:40:56 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char*)s1;
	tmp2 = (char*)s2;
	while (n--)
	{
		if (s2 > s1)
			*tmp1++ = *tmp2++;
		else
			*(tmp1 + n) = *(tmp2 + n);
	}
	return (s1);
}
