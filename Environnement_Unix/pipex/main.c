/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:32:00 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/31 14:50:53 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fcntl.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	"pipex.h"

void		cmd_not_found(char *cmd)
{
	ft_putstr(2, cmd);
	ft_putstr(2, ": Command not found\n");
}

int			pipex(char **av, char **envp)
{
	pid_t	pid;
	t_path	*list;
	int		fdpipe[2];

	list = get_paths(envp);
	if (pipe(fdpipe) == -1 || (pid = fork()) == -1)
		return (1);
	if (pid > 0)
	{
		close(fdpipe[0]);
		dup2(fdpipe[1], 1);
		close(fdpipe[1]);
		if (parse_buf(av[2], list, envp) == -1)
			cmd_not_found(av[2]);
	}
	else
	{
		close(fdpipe[1]);
		dup2(fdpipe[0], 0);
		close(fdpipe[0]);
		if (parse_buf(av[3], list, envp) == -1)
			cmd_not_found(av[3]);
	}
	return (0);
}

int			main(int ac, char **av, char **envp)
{
	int		fdfile[2];

	if (ac != 5)
		return (ft_putstr(2, "usage: ./pipex file1 cmd1 cmd2 file2\n"));
	if ((fdfile[0] = open(av[1], O_RDONLY)) == -1
		|| (fdfile[1] = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0644)) == -1)
	{
		ft_putstr(2, av[1]);
		return (ft_putstr(2, ": No such file or directory\n"));
	}
	if (dup2(fdfile[0], 0) == -1 || dup2(fdfile[1], 1) == -1)
		return (1);
	pipex(av, envp);
	return (0);
}
