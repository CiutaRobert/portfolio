/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:12:41 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/25 14:34:36 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<stdlib.h>

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*tmp;

	if (!s || !f)
		return (NULL);
	tmp = (char *)s;
	i = 0;
	while (tmp[i])
		++i;
	if ((str = (char *)malloc(i)) == NULL)
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		str[i] = f(i, tmp[i]);
		++i;
	}
	return (str);
}
