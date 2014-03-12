/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:31:37 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/25 14:35:48 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0 && i < n)
		++i;
	if ((s1[i] == 0 && s2[i] == 0) || i == n)
		return (1);
	return (0);
}
