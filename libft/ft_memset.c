/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:52:14 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/19 14:57:57 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>

void		*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;

	tmp = (char*)b;
	while (len--)
		*tmp++ = c;
	return (b);
}
