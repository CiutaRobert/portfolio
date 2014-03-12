/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ihm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 15:53:01 by jzak              #+#    #+#             */
/*   Updated: 2014/01/31 22:00:20 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "printf.h"
#include "ncurses.h"
#include "VM.h"

t_ihm					ihm = {
	.nbr_collumn = 0,
	.nbr_line = 0,
	.main = NULL,
	.info = NULL,
	.print = NULL,
	.panels = { 0 },
	.status = RUN,
	.battle = NULL,
	.mode = 0
};

static t_curses_evt		curses_evt[] = {
	{ ' ', pause_evt },
	{ ECHAP, quit_evt },
	{ 'q', quit_evt },
	{ 'i', info_evt },
	{ 'p', print_evt },
	{ 'n', step_evt },
	{ 0, NULL }
};

static void		init_ihm_color(void)
{
	curs_set(0);
	init_color(COLOR_RED, 800, 0, 0);
	init_pair(9, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
}

void			init_ihm(void)
{
	int		size_line;
	int		size_col;

	if (ihm.mode)
	{
		init_curses();
		getmaxyx(stdscr, ihm.nbr_line, ihm.nbr_collumn);
		size_line = ihm.nbr_line - LINE_INFO;
		size_col = ihm.nbr_collumn - COL_INFO;
		ihm.main = newwin(ihm.nbr_line, ihm.nbr_collumn, 0, 0);
		ihm.info = newwin(LINE_INFO, COL_INFO, size_line, size_col);
		ihm.print = newwin(LINE_INFO, COL_INFO, size_line, 0);
		box(ihm.info, 0, 0);
		box(ihm.print, 0, 0);
		ihm.panels[0] = new_panel(ihm.info);
		ihm.panels[1] = new_panel(ihm.print);
		ihm.panels[2] = new_panel(ihm.main);
		hide_panel(ihm.panels[0]);
		hide_panel(ihm.panels[1]);
		update_panels();
		init_ihm_color();
	}
}

void			print_ihm(const char *format, ...)
{
	va_list		va;
	static int	line = 2;

	va_start(va, format);
	if (ihm.mode)
	{
		if (line == 18)
		{
			line = 2;
			werase(ihm.print);
		}
		else
			++line;
		wmove(ihm.print, line, 2);
		vw_printw(ihm.print, format, va);
		box(ihm.print, 0, 0);
	}
	else
		ft_vdprintf(STDOUT_FILENO, format, va);
	va_end(va);
}

void			draw_ihm(t_battle *battle)
{
	if (ihm.mode)
	{
		ihm.battle = battle;
		draw_main();
		draw_info();
		draw_print();
		update_panels();
		doupdate();
		handle_key_event(curses_evt, &ihm);
	}
}

void			destroy_ihm(void)
{
	if (ihm.mode)
	{
		del_panel(ihm.panels[0]);
		del_panel(ihm.panels[1]);
		delwin(ihm.main);
		delwin(ihm.info);
		destroy_curses();
	}
	ihm.mode = 0;
}
