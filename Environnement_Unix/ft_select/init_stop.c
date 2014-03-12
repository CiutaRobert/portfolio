/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:03:17 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/12 22:03:18 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fcntl.h>
#include	<stdlib.h>
#include	<term.h>
#include	"ft_select.h"

char		*init_termcaps(t_all *all)
{
	all->term.c_lflag &= ~(ICANON);
	all->term.c_lflag &= ~(ECHO);
	all->term.c_cc[VMIN] = 1;
	all->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &all->term) == -1)
		return (puterror("tcsetattr"));
	return (OK);
}

char		*stop_termcaps(t_all *all)
{
	all->term.c_lflag |= (ICANON | ECHO);
	tputs(all->opt[VISIBLE_CURSOR], 1, ft_putchar2);
	tputs(all->opt[TERM_END], 1, ft_putchar2);
	if (tcsetattr(0, TCSANOW, &all->term) == -1)
		return (puterror("tcsetattr"));
	return (OK);
}

char		*init_all(t_all *all, int ac, char **av)
{
	int		i;
	char	*cap[9] = {"cm", "us", "ue", "mr", "me", "vi", "ve", "ti", "te"};

	all->full = NULL;
	if ((all->fd = open("/dev/tty", O_WRONLY)) == -1)
		return (puterror("open"));
	all->last_elem = ac - 2;
	i = -1;
	while (++i < 9)
	{
		if ((all->opt[i] = tgetstr(cap[i], NULL)) == NULL)
			return (puterror("tgetstr"));
	}
	i = 0;
	while (++i < ac)
		lst_push_back(&all->full, av[i], i - 1);
	tputs(all->opt[TERM_INIT], 1, ft_putchar2);
	tputs(all->opt[HIDDEN_CURSOR], 1, ft_putchar2);
	return (OK);
}
