/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 21:34:31 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/30 17:09:44 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<unistd.h>
#include	"pipex.h"

static int	count_words(char *buf)
{
	int		i;
	int		words;

	if (!buf)
		return (-1);
	words = 0;
	i = -1;
	while (buf[++i])
	{
		while (buf[i] && (buf[i] == ' ' || buf[i] == '\t' || buf[i] == '\n'))
			++i;
		if (buf[i])
		{
			while (buf[i] && buf[i] != ' ' && buf[i] != '\t' && buf[i] != '\n')
				++i;
			++words;
		}
		if (!buf[i])
			--i;
	}
	return (words);
}

static int	count_letters(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] && buf[i] != ' ' && buf[i] != '\t' && buf[i] != '\n')
		++i;
	return (i);
}

static char	*concat_path(t_path *s1, const char *s2)
{
	int		i;
	int		j;
	char	*new_str;

	if (!s2 ||
		(new_str = (char *)malloc(s1->len + ft_strlen(s2) + 2)) == NULL)
		return (NULL);
	i = 0;
	while (s1->path && i < s1->len)
	{
		new_str[i] = s1->path[i];
		++i;
	}
	new_str[i++] = '/';
	j = -1;
	while (s2 && s2[++j])
		new_str[i + j] = s2[j];
	new_str[i + j] = 0;
	return (new_str);
}

char		**ft_strsplit(char *buf)
{
	int		i;
	int		j;
	int		pos;
	int		words;
	char	**tab;

	if ((tab = malloc(sizeof(char *) * ((words = count_words(buf)) + 1))) == 0)
		return (NULL);
	tab[words] = NULL;
	i = -1;
	pos = 0;
	while (++i < words)
	{
		while (buf[pos] && (buf[pos] == ' ' || buf[pos] == '\t'
							|| buf[pos] == '\n'))
			++pos;
		if ((tab[i] = malloc(count_letters(buf + pos) + 1)) == NULL)
			return (NULL);
		j = 0;
		while (buf[pos] && buf[pos] != ' ' && buf[pos] != '\t'
				&& buf[pos] != '\n')
			tab[i][j++] = buf[pos++];
		tab[i][j] = 0;
	}
	return (tab);
}

int			parse_buf(char *buf, t_path *list, char **envp)
{
	t_path	*tmp;
	char	*new_path;
	char	**tab;
	int		is_exe;

	if ((tab = ft_strsplit(buf)) == NULL)
		return (free_tab(tab, -1));
	is_exe = (execve(tab[0], tab, envp) != -1 ? 1 : 0);
	tmp = list;
	while (tmp && !is_exe)
	{
		if ((new_path = concat_path(tmp, tab[0])) == NULL)
			return (free_tab(tab, -1));
		if (execve(new_path, tab, envp) != -1)
			is_exe = 1;
		free(new_path);
		tmp = tmp->next;
	}
	if (!is_exe)
		return (free_tab(tab, -1));
	return (free_tab(tab, 0));
}
