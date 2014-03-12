/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 21:34:02 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/09 01:56:32 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<signal.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"ft_sh.h"

static void	ignore_signal(int sig)
{
	(void)sig;
}

void		ignore_all_signals(void)
{
	int		i;

	i = -1;
	while (++i <= 64)
	{
		if (i != SIGKILL && i != SIGSTOP)
			signal(i, &ignore_signal);
	}
}

void		handle_signal(int status)
{
	int		i;
	int		sig;
	int		sig_h[] = {SIGINT, SIGSEGV, SIGKILL, SIGTERM, SIGABRT, SIGBUS};
	char	*msg[] = {"\n", "Segmentation fault (core dumped)\n",
					"Killed\n", "Terminated\n", "Abort (core dumped)\n",
					"Bus error (core dumped)\n"};

	if (!WIFEXITED(status) && WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		i = -1;
		while (++i < 6)
		{
			if (sig == sig_h[i])
			{
				ft_putstr_fd(2, msg[i]);
				i = 41;
			}
		}
		if (i != 42)
			ft_putstr_fd(2, "Program died with some exotic signal\n");
	}
}
