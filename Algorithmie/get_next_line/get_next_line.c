/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:56:36 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/02 20:51:53 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<unistd.h>
#include			<stdlib.h>
#include			"get_next_line.h"

int					ft_strlen(char const *str)
{
	int				i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	int				s1_len;
	int				s2_len;
	char			*str;

	if ((str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	s1_len = -1;
	while (s1[++s1_len])
		str[s1_len] = s1[s1_len];
	s2_len = -1;
	while (s2[++s2_len])
		str[s1_len + s2_len] = s2[s2_len];
	str[s1_len + s2_len] = 0;
	free((void *)s1);
	free((void *)s2);
	return (str);
}

int					complete_line(int const fd, char **line)
{
	int				ret;
	char			*new_line;

	new_line = NULL;
	ret = get_next_line(fd, &new_line);
	if (new_line != NULL)
		*line = ft_strjoin(*line, new_line);
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	static char		buf[BUFF_SIZE + 1] = {0};
	static int		i = 0;
	int				j;

	if (!buf[i])
	{
		if ((i = read(fd, buf, BUFF_SIZE)) <= 0)
			return (i);
		buf[i] = 0;
		i = 0;
	}
	if ((*line = (char *)malloc(BUFF_SIZE + 1)) == NULL)
		return (-1);
	j = 0;
	while (buf[i] && buf[i] != '\n' && j < BUFF_SIZE)
		(*line)[j++] = buf[i++];
	(*line)[j] = 0;
	if (buf[i] == '\n')
		++i;
	else
		return (complete_line(fd, line));
	return (1);
}
