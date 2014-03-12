/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:23:44 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/19 20:34:51 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	while (s1[i])
		++i;
	if ((str = (char *)malloc(sizeof(char) * i)) == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	str[i] = 0;
	return (str);
}
