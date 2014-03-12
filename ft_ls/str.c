/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 20:24:04 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/15 20:24:39 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(const char *str)
{
	int		i;

	if (!str)
		write(1, "(null)", 6);
	else
	{
		i = 0;
		while (str[i])
			++i;
		write(1, str, i);
	}
}

void		ft_putnbr(int n)
{
	char	c;

	if (n / 10)
		ft_putnbr(n / 10);
	if (n < 0 && n > -10)
		write(1, "-", 1);
	n %= 10;
	if (n < 0)
		n *= -1;
	c = n + '0';
	write(1, &c, 1);
}

int			ft_strlen(const char *str)
{
	int		len;

	if (!str)
		return (-1);
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

	if (!s1 || !s2 || (new_str = (char *)malloc(ft_strlen(s1)
												+ ft_strlen(s2) + 2)) == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		new_str[i] = s1[i];
	if (!(s1[0] == '/' && !s1[1]))
		new_str[i++] = '/';
	j = -1;
	while (s2[++j])
		new_str[i + j] = s2[j];
	new_str[i + j] = 0;
	return (new_str);
}
