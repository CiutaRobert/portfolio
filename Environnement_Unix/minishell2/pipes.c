/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 23:45:23 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/26 15:07:43 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<unistd.h>
#include		"ft_sh.h"

static int		create_pipe(char **cmd_pipe, int fd_in, int i)
{
	static int	fdpipe[2];

	if (i)
		fd_in = fdpipe[0];
	if (pipe(fdpipe) == -1)
		return (-1);
	if (cmd_pipe[i + 1])
	{
		dup2(fdpipe[1], 1);
		close(fdpipe[1]);
	}
	dup2(fd_in, 0);
	return (0);
}

int				check_pipe(char *cmd, t_path **list, char ***envp)
{
	int			i;
	char		**cmd_pipe;
	char		*tmp;
	int			save[2];
	int			fd_in;

	if ((cmd_pipe = ft_strsplit(cmd, "|")) == NULL)
		return (-1);
	fd_in = 0;
	i = -1;
	while (cmd_pipe[++i])
	{
		save[0] = dup(0);
		save[1] = dup(1);
		if ((tmp = check_redir(cmd_pipe[i])))
		{
			if (create_pipe(cmd_pipe, fd_in, i) == -1
				|| exec_cmd(tmp, list, envp) == -1)
				return (free_tab(cmd_pipe));
		}
		dup2(save[0], 0);
		dup2(save[1], 1);
	}
	free_tab(cmd_pipe);
	return (1);
}
