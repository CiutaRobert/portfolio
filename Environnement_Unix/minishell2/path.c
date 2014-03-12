/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 21:34:11 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/26 15:17:34 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		"ft_sh.h"

static t_path	*path_new(char *path, int len)
{
	t_path		*new;

	if ((new = malloc(sizeof(t_path))) == NULL)
		return (NULL);
	new->path = path;
	new->len = len;
	new->next = NULL;
	return (new);
}

void			path_add(t_path **list, char *path, int len)
{
	t_path		*new;
	t_path		*tmp;

	new = path_new(path, len);
	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static void		parse_env(char *path_line, t_path **list)
{
	int			start;
	int			end;

	start = 5;
	end = 4;
	while (path_line[++end])
	{
		if (path_line[end] == ':')
		{
			path_add(list, path_line + start, end - start);
			start = end + 1;
		}
	}
	if (start != end)
		path_add(list, path_line + start, end - start);
}

int				free_paths(t_path *list, int is_child)
{
	t_path		*tmp;
	t_path		*tmp2;

	tmp = list;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	if (!is_child)
		ft_putstr(1, "exit\n");
	return (0);
}

t_path			*get_paths(char **envp)
{
	int			i;
	t_path		*list;

	list = NULL;
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			parse_env(envp[i], &list);
	}
	return (list);
}
