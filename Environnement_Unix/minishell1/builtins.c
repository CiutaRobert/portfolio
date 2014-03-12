/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 21:34:24 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/29 22:18:49 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	"ft_sh.h"

static void	cmd_env(char **tab, char ***envp)
{
	int		i;

	(void)tab;
	i = -1;
	while ((*envp)[++i])
	{
		ft_putstr(1, (*envp)[i]);
		ft_putstr(1, "\n");
	}
}

static void	cmd_setenv(char **tab, char ***envp)
{
	int		i;

	if (!tab[1])
		return (cmd_env(tab, envp));
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(tab[1], (*envp)[i], ft_strlen(tab[1])))
		{
			ft_putstr(1, "mise a jour de la variable ");
			ft_putstr(1, tab[1]);
			ft_putstr(1, "\n");
			return ;
		}
	}
	ft_putstr(1, "creation de la variable ");
	ft_putstr(1, tab[1]);
	ft_putstr(1, "\n");
}

static void	cmd_unsetenv(char **tab, char ***envp)
{
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(tab[1], (*envp)[i], ft_strlen(tab[1])))
		{
			ft_putstr(1, "destruction de la variable ");
			ft_putstr(1, tab[1]);
			ft_putstr(1, "\n");
			return ;
		}
	}
}

static void	cmd_cd(char **tab, char ***envp)
{
	int		i;

	i = -1;
	if (!tab[1])
	{
		while ((*envp)[++i])
		{
			if (!ft_strncmp((*envp)[i], "HOME=", 5)
				&& chdir((*envp)[i] + 5) == -1)
				ft_putstr(2, "cd: Bad PWD\n");
		}
		return ;
	}
	if (chdir(tab[1]) == -1)
	{
		ft_putstr(2, tab[1]);
		ft_putstr(2, ": No such file or directory\n");
	}
}

int			is_builtin(char *buf, char ***envp)
{
	int		i;
	char	**tab;
	t_bltn	bltn[] = {{"env", &cmd_env}, {"setenv", &cmd_setenv},
					{"cd", &cmd_cd}, {"unsetenv", &cmd_unsetenv}};

	if ((tab = ft_strsplit(buf)) == NULL)
		return (1);
	if (!ft_strcmp("exit", tab[0]))
		return (free_tab(tab));
	i = -1;
	while (++i < 4)
	{
		if (!ft_strcmp(bltn[i].name, tab[0]))
		{
			bltn[i].func(tab, envp);
			free_tab(tab);
			return (1);
		}
	}
	free_tab(tab);
	return (0);
}
