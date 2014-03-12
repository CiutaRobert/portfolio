/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ihm_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 20:30:47 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 22:51:48 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VM.h"

static int			get_champion_color(int id)
{
	if (id >= 1 && id <= 7)
		return (id);
	return (9);
}

static void			get_pc(t_battle *battle, char *addr)
{
	int			i;
	t_process	*process;

	i = 0;
	while (battle->champion[i] != NULL)
	{
		process = battle->champion[i]->process;
		while (process != NULL)
		{
			if (process->pc == addr)
				wattron(ihm.main, A_REVERSE);
			process = process->next;
		}
		++i;
	}
}

void				draw_main(void)
{
	int			i;
	int			color;
	t_battle	*battle;

	battle = ihm.battle;
	i = 0;
	wmove(ihm.main, 0, 0);
	while (i < MEM_SIZE)
	{
		color = get_champion_color(battle->belongs[i]);
		get_pc(ihm.battle, &battle->memory[i]);
		wattron(ihm.main, COLOR_PAIR(color));
		wprintw(ihm.main, "%02X", (t_uint)(unsigned char)battle->memory[i]);
		++i;
		wattroff(ihm.main, A_REVERSE);
		wattroff(ihm.main, COLOR_PAIR(color));
		if (i % (ihm.nbr_collumn / 3) == 0)
			wprintw(ihm.main, "\n");
		else
			wprintw(ihm.main, " ");
	}
}

void				draw_info(void)
{
	if (panel_hidden(ihm.panels[0]) == FALSE)
	{
		if (ihm.status == PAUSE)
			PRINT(1, COL_INFO / 2 - 7, "*** PAUSED ***")
		else
			PRINT(1, COL_INFO / 2 - 7, "*** RUN ***   ")
		PRINT(2, 2, "cycle        : %-15lu", ihm.battle->cycle)
		PRINT(3, 2, "cycle_to_die : %-15u", ihm.battle->cycle_to_die)
		PRINT(6, 2, "CYCLE_TO_DIE : %-15u", CYCLE_TO_DIE)
		PRINT(7, 2, "CYCLE_DELTA  : %-15u", CYCLE_DELTA)
		PRINT(8, 2, "NBR_LIVE     : %-15u", NBR_LIVE)
		PRINT(9, 2, "MAX_CHECKS   : %-15u", MAX_CHECKS)
	}
}

void				draw_print(void)
{
	mvwprintw(ihm.print, 1, COL_INFO / 2 - 10, "*** PRINT BOX ***");
}
