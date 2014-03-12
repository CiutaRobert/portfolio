/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 21:09:51 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/08 22:32:58 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<unistd.h>
#include		<stdlib.h>
#include		<signal.h>
#include		"minitalk.h"

void			get_sig(int sig, int *cur_int, int pid, int maxbits)
{
	static int	count = 0;

	if (sig == SIGUSR2)
		*cur_int += 1 << count;
	count = (count + 1) & maxbits;
	if (kill(pid, SIGUSR1) == -1)
		ft_putstr("Error with kill, the client probably disconnect\n");
}

void			print_buf(char **buf, int *total, int *len, int pid)
{
	ft_putstr("UID:");
	ft_putnbr(pid);
	ft_putstr(":\"");
	ft_putstr(*buf);
	ft_putstr("\"\n");
	*total = 0;
	*len = 0;
	free(*buf);
	*buf = NULL;
}

void			handle_sig(int sig, siginfo_t *siginfo, void *context)
{
	static int	total = 0;
	static int	len = 0;
	static char	*buf;
	static int	pid = 0;

	(void)context;
	pid = (siginfo->si_pid ? siginfo->si_pid : pid);
	if (total < 32)
		get_sig(sig, &len, pid, 31);
	else
	{
		if (total == 32 && (buf = malloc(sizeof(char) * (len + 1))) == NULL)
		{
			ft_putstr("Error with malloc\n");
			exit(EXIT_FAILURE);
		}
		buf[len] = 0;
		if (!((total - 32) % 8))
			buf[(total / 8) - 4] = 0;
		get_sig(sig, (int *)&buf[(total / 8) - 4], pid, 7);
	}
	++total;
	if ((total / 8) - 4 == len)
		print_buf(&buf, &total, &len, pid);
}

int				main(void)
{
	struct sigaction act;

	act.sa_sigaction = &handle_sig;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		return (ft_putstr("Error with sigaction on SIGUSR1\n"));
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		return (ft_putstr("Error with sigaction on SIGUSR2\n"));
	ft_putstr("SERVER READY, PID: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (1)
		;
	return (0);
}
