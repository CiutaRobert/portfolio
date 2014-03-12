/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 15:45:17 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/04 20:03:38 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<unistd.h>

int			ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	write(1, str, i);
	return (1);
}

static int	ft_strlen(const char *str)
{
	int		len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		++len;
	return (len);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*new_str;

	if (!s2 ||
		(new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		++i;
	}
	j = -1;
	while (s2 && s2[++j])
		new_str[i + j] = s2[j];
	new_str[i + j] = 0;
	if (!s1)
		free((char *)s1);
	return (new_str);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		nb;
	int		sign;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	nb = 0;
	sign = (str[i] == '-' ? -1 : 1);
	i = (str[i] == '-' || str[i] == '+' ? i : i - 1);
	while (str[++i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += (str[i] - '0') * sign;
	}
	return (nb);
}
