/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:26:10 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/26 15:31:10 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	char	*tmp;

	if (*s2 == 0)
		return ((char *)s1);
	while (*s1 && n)
    {
		tmp = (char *)s1;
		i = 0;
		while (*tmp && *tmp == s2[i] && n)
		{
			++tmp;
			++i;
			--n;
		}
		if (!s2[i])
			return (tmp - i);
		if (i != -1)
		{
			++n;
			++s1;
		}
		--n;
    }
	return (NULL);
}
