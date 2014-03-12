/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 21:34:24 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/09 01:55:36 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<unistd.h>
#include	"ft_sh.h"

static void	cmd_env(char **tab, t_path **list, char ***envp)
{
	int		i;

	(void)list;
	(void)tab;
	i = -1;
	while ((*envp)[++i])
	{
		ft_putstr_fd(1, (*envp)[i]);
		ft_putstr_fd(1, "\n");
	}
}

void		cmd_setenv(char **tab, t_path **list, char ***envp)
{
	char	**new_env;
	char	*new_line;
	int		i;

	if (!tab[1])
		return (cmd_env(tab, list, envp));
	new_line = ft_strjoin(tab[1], tab[2], '=');
	i = -1;
	while ((*envp)[++i])
	{
		if (!ft_strncmp(tab[1], (*envp)[i], ft_strlen(tab[1]))
			&& (*envp)[i][ft_strlen(tab[1])] == '=')
		{
			(*envp)[i] = new_line;
			free_paths(*list, 1);
			*list = get_paths(*envp);
			return ;
		}
	}
	new_env = copy_env(*envp, new_line, i, 0);
	free_env(*envp);
	free(new_line);
	*envp = new_env;
	free_paths(*list, 1);
	*list = get_paths(*envp);
}

static void	cmd_unsetenv(char **tab, t_path **list, char ***envp)
{
	int		i;

	if (!tab[1])
		return ;
	i = -1;
	while ((*envp)[++i])
	{
		if (!ft_strncmp(tab[1], (*envp)[i], ft_strlen(tab[1]))
			&& (*envp)[i][ft_strlen(tab[1])] == '=')
		{
			delete_one_from_env(envp, i);
			free_paths(*list, 1);
			*list = get_paths(*envp);
			return ;
		}
	}
}

static void	cmd_cd(char **tab, t_path **list, char ***envp)
{
	int		i;

	(void)list;
	if (!tab[1])
	{
		i = -1;
		while ((*envp)[++i])
		{
			if (!ft_strncmp((*envp)[i], "HOME=", 5)
				&& chdir((*envp)[i] + 5) == -1)
				ft_putstr_fd(2, "cd: bad HOME environnement\n");
		}
		set_pwds(list, envp);
		return ;
	}
	if (tab[1][0] == '-' && !tab[1][1])
		go_oldpwd(envp);
	else if (chdir(tab[1]) == -1)
	{
		ft_putstr_fd(2, tab[1]);
		ft_putstr_fd(2, ": No such file or directory\n");
		return ;
	}
	set_pwds(list, envp);
}

int			is_builtin(char *buf, t_path **list, char ***envp)
{
	int		i;
	char	**tab;
	t_bltn	bltn[] = {{"env", &cmd_env}, {"setenv", &cmd_setenv},
					{"cd", &cmd_cd}, {"unsetenv", &cmd_unsetenv}};

	if ((tab = ft_strsplit(buf, " \t")) == NULL || !tab[0])
		return (-1 * free_tab(tab));
	if (!ft_strcmp("exit", tab[0]))
		return (free_tab(tab));
	i = -1;
	while (++i < 4)
	{
		if (!ft_strcmp(bltn[i].name, tab[0]))
		{
			bltn[i].func(tab, list, envp);
			free_tab(tab);
			return (1);
		}
	}
	free_tab(tab);
	return (0);
}
