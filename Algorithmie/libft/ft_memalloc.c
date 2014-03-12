/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:34:29 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/22 14:50:53 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

void		*ft_memalloc(size_t size)
{
	size_t	i;
	void	*ptr;
	char	*tmp;

	if ((ptr = malloc(size)) == NULL)
		return (NULL);
	i = -1;
	tmp = (char *)ptr;
	while (++i < size)
		tmp[i] = 0;
	return (ptr);
}
