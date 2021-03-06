/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:27:18 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/11/25 00:27:16 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		len;

	len = 0;
	while (s1[len])
		++len;
	i = 0;
	while (s2[i])
    {
		s1[len + i] = s2[i];
		++i;
    }
	s1[len + i] = 0;
	return (s1);
}
