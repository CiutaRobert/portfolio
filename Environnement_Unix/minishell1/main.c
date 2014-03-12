/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 21:33:46 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/29 21:33:46 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"ft_sh.h"

int			exec_cmd(char *buf, t_path *list, char **envp)
{
	pid_t	pid;
	int		status;

	if ((status = is_builtin(buf, &envp)))
		return (status);
	if ((pid = fork()) == -1)
		return (ft_putstr(2, "gabtoubl_sh: Error with fork\n"));
	if (pid > 0)
	{
		if (wait(&status) == -1)
			return (ft_putstr(2, "gabtoubl_sh: Error with wait\n"));
		handle_signal(status);
	}
	else
		return (parse_buf(buf, list, envp));
	return (0);
}

void		print_intro_msg(void)
{
	ft_putstr(1, "   ___      _     _              _     _         _\n");
	ft_putstr(1, "  / _ \\__ _| |__ | |_ ___  _   _| |__ | |    ___| |__\n");
	ft_putstr(1, " / /_\\/ _` | '_ \\| __/ _ \\| ");
	ft_putstr(1, "| | | '_ \\| |   / __| '_ \\\n");
	ft_putstr(1, "/ /_\\\\ (_| | |_) | || (_) | |_| ");
	ft_putstr(1, "| |_) | |   \\__ \\ | | |\n");
	ft_putstr(1, "\\____/\\__,_|_.__/ \\__\\___/ ");
	ft_putstr(1, "\\__,_|_.__/|_|___|___/_| |_|\n");
	ft_putstr(1, "                                       |_____|\n");
}

int			main(int ac, char **av, char **envp)
{
	int		ret;
	t_path	*list;
	char	buf[BUFF_SIZE + 1];

	(void)ac;
	(void)av;
	list = get_paths(envp);
	print_intro_msg();
	ignore_all_signals();
	while (1)
	{
		ft_putstr(1, "Gabtoubl_sh $>");
		if ((ret = read(0, buf, BUFF_SIZE)) <= 0)
		{
			if (ret == 0)
				return (free_paths(list, 0));
			ft_putstr(2, "gabtoubl_sh: Error with read\n");
		}
		else
			buf[ret] = 0;
		if (ret > 1 && exec_cmd(buf, list, envp) == -1)
			return (free_paths(list, 1));
	}
	return (0);
}
