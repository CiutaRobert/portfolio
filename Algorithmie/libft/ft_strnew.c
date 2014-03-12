/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 21:44:09 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/25 14:44:32 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	if ((str = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	i = -1;
	while (++i < size + 1)
		str[i] = '\0';
	return (str);
}
