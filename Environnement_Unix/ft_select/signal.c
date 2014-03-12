/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:03:29 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/12 22:03:30 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<sys/ioctl.h>
#include	<signal.h>
#include	<unistd.h>
#include	<term.h>
#include	"ft_select.h"

void		get_sigwinch(int sig)
{
	t_win	size;

	(void)sig;
	if (ioctl(g_all.fd, TIOCGWINSZ, &size) == -1)
	{
		puterror("ioctl");
		exit(EXIT_FAILURE);
	}
	g_all.line = size.ws_row;
	g_all.column = size.ws_col;
	lst_aff(&g_all);
}

void		get_sigtstp(int sig)
{
	char	stop[2] = {g_all.term.c_cc[VSUSP], 0};

	if (isatty(1))
	{
		(void)sig;
		stop_termcaps(&g_all);
		signal(SIGTSTP, SIG_DFL);
		if (ioctl(0, TIOCSTI, stop) == -1)
		{
			puterror("ioctl");
			exit(EXIT_FAILURE);
		}
	}
}

void		get_sigcont(int sig)
{
	(void)sig;
	init_termcaps(&g_all);
	signal(SIGTSTP, &get_sigtstp);
	tputs(g_all.opt[TERM_INIT], 1, ft_putchar2);
	tputs(g_all.opt[HIDDEN_CURSOR], 1, ft_putchar2);
	lst_aff(&g_all);
}

void		get_other_sig(int sig)
{
	(void)sig;
	stop_termcaps(&g_all);
	close(g_all.fd);
	exit(EXIT_FAILURE);
}
