/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:41:21 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 14:24:34 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VM.h"
#include "printf.h"
#include "libft.h"

void			run_process(t_battle *battle)
{
	t_process	*process;

	process = battle->curr_champion->process;
	while (process != NULL)
	{
		battle->curr_process = process;
		if (process->consumed + get_op_consumption(process) <= battle->cycle)
			process->consumed += execute_op(battle);
		process = process->next;
	}
	process = battle->curr_champion->process;
}

/*
** Execute all champions for next round, with sync support.
** (aka until cycle consumption pseudo equality)
*/
static void		run_round(t_battle *battle)
{
	int			i;

	i = battle->nbr_champion - 1;
	while (i >= 0)
	{
		battle->curr_champion = battle->champion[i];
		if (battle->champion[i]->is_dead < 1)
			run_process(battle);
		--i;
	}
}

/*
** runs the corewar battle, and returns the VM termination status
*/
int				run_battle(t_battle *battle)
{
	t_uint		cycle_to_die;

	cycle_to_die = 0;
	while (ihm.status != QUIT)
	{
		draw_ihm(battle);
		if (ihm.status == RUN || ihm.status == STEP)
		{
			if (cycle_to_die >= battle->cycle_to_die)
			{
				cycle_to_die = 0;
				if (is_dead(battle) == true)
					return (HAS_WINNER);
			}
			run_round(battle);
			cycle_to_die++;
			battle->cycle++;
			if (battle->dump != 0 && battle->cycle == (t_ulong)battle->dump)
				return (CORE_DUMP);
		}
		if (ihm.status == STEP)
			ihm.status = PAUSE;
	}
	return (0);
}

/*
** free battle object
*/
void			free_battle(t_battle *battle)
{
	int			i;
	t_champion	*champ;
	t_process	*process;
	t_process	*next;

	i = 0;
	while ((champ = battle->champion[i]) != NULL)
	{
		process = battle->champion[i]->process;
		while (process != NULL)
		{
			next = process->next;
			free(process);
			process = next;
		}
		free(battle->champion[i]);
		++i;
	}
	free(battle);
}
