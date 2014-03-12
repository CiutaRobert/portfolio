/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:41:04 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/25 14:36:42 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<stdlib.h>

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s || (str = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	i = start;
	while (i - start < len)
	{
		str[i - start] = s[i];
		++i;
	}
	str[i - start] = 0;
	return (str);
}
