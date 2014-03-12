/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 09:42:16 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/26 11:28:52 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
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

char		*ft_strjoin(const char *s1, const char *s2, char sep)
{
	int		i;
	int		j;
	char	*new_str;

	if ((new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2)) == NULL)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		new_str[i] = s1[i];
	new_str[i] = sep;
	++i;
	j = -1;
	while (s2 && s2[++j])
		new_str[i + j] = s2[j];
	j = (j == -1 ? 0 : j);
	new_str[i + j] = 0;
	return (new_str);
}
