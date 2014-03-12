/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 10:58:35 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/26 12:19:28 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<unistd.h>
#include	"ft_sh.h"

void		go_oldpwd(char ***envp)
{
	int		i;
	int		is_old;

	is_old = 0;
	i = -1;
	while ((*envp)[++i])
	{
		if (!ft_strncmp((*envp)[i], "OLDPWD=", 7)
			&& (is_old = 1) && chdir((*envp)[i] + 7) == -1)
			ft_putstr(2, "cd: bad OLDPWD environnement\n");
	}
	if (!is_old)
		ft_putstr(2, "cd: no OLDPWD environnement\n");
}

void		set_pwds(t_path **list, char ***envp)
{
	char	*tab[3] = {"setenv", "PWD", NULL};
	char	*tab_old[3] = {"setenv", "OLDPWD", NULL};
	char	*buf;
	int		size;
	int		i;

	i = -1;
	while ((*envp)[++i])
	{
		if (!ft_strncmp((*envp)[i], "PWD=", 4))
			tab_old[2] = (*envp)[i] + 4;
	}
	size = 300;
	buf = malloc(size);
	while (!getcwd(buf, size))
	{
		size += 200;
		free(buf);
		buf = malloc(size);
	}
	tab[2] = buf;
	cmd_setenv(tab, list, envp);
	cmd_setenv(tab_old, list, envp);
	free(buf);
}
