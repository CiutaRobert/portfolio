/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:03:17 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/09 03:42:56 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<term.h>
#include	<stdlib.h>
#include	"ft_sh.h"

static int		start_termcaps(t_all *all)
{
	int			i;
	char		*term_name;

	all->max_y = 0;
	if ((term_name = getenv("TERM")) == NULL)
		return (puterror("getenv"));
	if (tgetent(NULL, term_name) <= 0)
		return (puterror("tgetent"));
	if (tcgetattr(0, &all->term) == -1)
		return (puterror("tcgetattr"));
	i = -1;
	while (++i < BUFF_SIZE)
		all->save[i] = 0;
	return (OK);
}

int				init_termcaps(t_all *all)
{
	static int	is_start = 0;
	int			i;

	if (!is_start && (is_start = 1) && start_termcaps(all) != OK)
		return (NOT_OK);
	all->term.c_lflag &= ~(ICANON);
	all->term.c_lflag &= ~(ECHO);
	all->term.c_cc[VMIN] = 1;
	all->term.c_cc[VTIME] = 0;
	i = -1;
	while (++i < BUFF_SIZE)
		all->line[i] = 0;
	if ((all->caps[MOVE_LEFT] = tgetstr("le", NULL)) == NULL
		|| (all->caps[MOVE_RIGHT] = tgetstr("nd", NULL)) == NULL
		|| (all->caps[CLEAR_EOL] = tgetstr("ce", NULL)) == NULL)
		return (puterror("tgetstr"));
	if (tcsetattr(0, TCSANOW, &all->term) == -1)
		return (puterror("tcsetattr"));
	return (OK);
}

int				stop_termcaps(t_all *all)
{
	all->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, TCSANOW, &all->term) == -1)
		return (puterror("tcsetattr"));
	return (OK);
}
