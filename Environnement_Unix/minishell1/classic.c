/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 13:10:45 by cvxfous           #+#    #+#             */
/*   Updated: 2013/12/29 21:45:40 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int			ft_strlen(const char *str)
{
	int		len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		++len;
	return (len);
}

int			ft_putstr(int fd, const char *str)
{
	if (!str)
		return (1);
	write(fd, str, ft_strlen(str));
	if (fd == 2)
		return (1);
	return (0);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	while (*tmp1 == *tmp2 && *tmp1)
	{
		++tmp1;
		++tmp2;
	}
	return (*tmp1 - *tmp2);
}

int			ft_strncmp(const char *s1, const char *s2, int n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	while (*tmp1 == *tmp2 && *tmp1 && n--)
	{
		++tmp1;
		++tmp2;
	}
	if (!n)
		return (0);
	return (*tmp1 - *tmp2);
}
