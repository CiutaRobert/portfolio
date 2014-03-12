/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 19:17:39 by fflorens          #+#    #+#             */
/*   Updated: 2014/01/29 19:17:40 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<unistd.h>
#include	<corewar_asm.h>

int			ft_putstr_fd(int fd, const char *str)
{
	if (!str)
		return (fd - 1);
	write(fd, str, ft_strlen(str));
	return (fd - 1);
}

int			ft_strcmp(char *s1, char *s2)
{
	int		fix;

	while (*s1 == *s2 && *s1 && *s1 != ' ' && *s1 != '\t')
	{
		++s1;
		++s2;
	}
	fix = (*s1 == ' ' ? ' ' : 0);
	fix = (*s1 == '\t' ? '\t' : fix);
	return (*s2 - *s1 + fix);
}

int			ft_strncmp(char *s1, char *s2, int len)
{
	while (*s1 == *s2 && *s1 && len--)
	{
		++s1;
		++s2;
	}
	if (!len && (!*s1 || *s1 == ',' || *s1 == ' ' || *s1 == '\t'))
		return (0);
	return (*s2 - *s1);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	int		j;
	int		i;

	if (!s2 && !s1)
		return ((char *)0x0);
	else
	{
		out = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (out)
		{
			i = -1;
			j = -1;
			while (s1[++i])
				out[i] = s1[i];
			while (s2[++j])
				out[i + j] = s2[j];
			out[i + j] = '\0';
		}
	}
	return (out);
}

int			ft_strlen(const char *str)
{
	if (!str || !*str)
		return (0);
	return (1 + ft_strlen((char *)(str + 1)));
}

