/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 21:08:17 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/08 21:37:39 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<signal.h>
#include	"minitalk.h"

int			g_pause = 1;

void		end_pause(int sig)
{
	(void)sig;
	g_pause = 0;
}

int			send_len(int pid, int len)
{
	int		i;
	int		sig;

	i = -1;
	while (++i < 32)
	{
		g_pause = 1;
		sig = len & 1;
		len >>= 1;
		if (kill(pid, SIGUSR1 + sig) == -1)
			return (ft_putstr("Error with kill, probably wrong PID\n"));
		while (g_pause)
			;
	}
	return (0);
}

int			send_str(int pid, char *str)
{
	int		i;
	int		j;
	int		sig;

	j = -1;
	while (str[++j])
	{
		i = -1;
		while (++i < 8)
		{
			g_pause = 1;
			sig = str[j] & 1;
			str[j] >>= 1;
			if (kill(pid, SIGUSR1 + sig) == -1)
				return (ft_putstr("Error with kill, probably wrong PID\n"));
			while (g_pause)
				;
		}
	}
	return (0);
}

int			main(int ac, char **av)
{
	int		pid;

	if (signal(SIGUSR1, &end_pause) == SIG_ERR)
		return (ft_putstr("Error with signal\n"));
	if (ac != 3)
		return (ft_putstr("usage: ./client SERVER_PID STRING\n"));
	pid = ft_atoi(av[1]);
	send_len(pid, ft_strlen(av[2]));
	send_str(pid, av[2]);
	return (0);
}
