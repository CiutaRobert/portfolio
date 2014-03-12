/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:08:43 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/21 13:22:20 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char*)s1;
	tmp2 = (char*)s2;
	while (n--)
	{
		*tmp1++ = *tmp2++;
		if (*(tmp1 - 1) == c)
			return (tmp1);
	}
	return (NULL);
}
