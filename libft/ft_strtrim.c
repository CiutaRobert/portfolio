/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:10:11 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/25 14:39:12 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		++start;
	end = 0;
	while (s[end])
		++end;
	while (end >= 0 && (s[--end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		--end;
	if (end < 0)
		start = 0;
	if ((str = (char *)malloc(end - start + 2)) == NULL)
		return (NULL);
	i = start - 1;
	while (++i <= end)
		str[i - start] = s[i];
	str[i - start] = 0;
	return (str);
}
