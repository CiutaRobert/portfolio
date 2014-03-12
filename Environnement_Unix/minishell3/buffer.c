/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 21:34:31 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/09 01:55:19 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/stat.h>
#include	"ft_sh.h"

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

int			parse_buf(char *buf, t_path *list, char **envp)
{
	t_path	*tmp;
	char	*new_path;
	char	**tab;
	int		is_exe;
	t_stat	st;

	if ((tab = ft_strsplit(buf, " \t")) == NULL)
		return (-1);
	is_exe = (execve(tab[0], tab, envp) != -1 ? 1 : 0);
	tmp = list;
	while (tmp && !is_exe)
	{
		new_path = concat_path(tmp, tab[0]);
		if (lstat(new_path, &st) != -1)
			execve(new_path, tab, envp);
		free(new_path);
		tmp = tmp->next;
	}
	ft_putstr_fd(2, tab[0]);
	ft_putstr_fd(2, ": Command not found.\n");
	return (free_tab(tab));
}
