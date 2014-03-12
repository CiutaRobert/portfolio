/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:54:26 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/20 14:25:31 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	tmp = (char *)s1;
	if (*s2 == 0)
		return (tmp);
	while (tmp[++i])
	{
		j = 0;
		while (tmp[i] && tmp[i] == s2[j])
		{
			++i;
			++j;
		}
		if (!s2[j])
			return (tmp + i - j);
		if (j != 0)
			--i;
	}
	return (NULL);
}
