/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:45:13 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/26 17:18:27 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len])
		++s1_len;
	s2_len = 0;
	while (s2[s2_len])
		++s2_len;
	if ((str = (char *)malloc(s1_len + s2_len + 1)) == NULL)
		return (NULL);
	s1_len = -1;
	while (s1[++s1_len])
		str[s1_len] = s1[s1_len];
	s2_len = -1;
	while (s2[++s2_len])
		str[s1_len + s2_len] = s2[s2_len];
	str[s1_len + s2_len] = 0;
	return (str);
}
