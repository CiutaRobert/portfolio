/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 14:42:20 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 10:43:49 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "ncurses.h"

t_bool			init_curses(void)
{
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	if (has_colors() == FALSE)
	{
		endwin();
		ft_printf("Your terminal does not support color\n");
		return (1);
	}
	start_color();
	return (0);
}

void			handle_key_event(t_curses_evt *evt, void *data)
{
	int		c;
	int		i;

	i = 0;
	timeout(1);
	c = getch();
	while (c != -1 && evt[i].fn != NULL)
	{
		if (evt[i].evt == c)
			evt[i].fn(data);
		++i;
	}
}

void			destroy_curses(void)
{
	clrtoeol();
	refresh();
	endwin();
}
