/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 16:42:05 by nmokrane          #+#    #+#             */
/*   Updated: 2014/02/02 22:45:24 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VM.h"

static void				kill_process(t_process **head, t_process *process)
{
	if (process->prev != NULL)
		process->prev->next = process->next;
	if (process->next != NULL)
		process->next->prev = process->prev;
	if (*head == process)
	{
		if (process->next != NULL)
			*head = process->next;
		else
			*head = NULL;
	}
	free(process);
}

static t_bool			kill_dead_process(t_process **head, int *nbr_live)
{
	t_process	*process;
	int			nbr;

	process = *head;
	nbr = *nbr_live;
	while (process != NULL)
	{
		if (process->nbr_live == 0)
			kill_process(head, process);
		else
		{
			*nbr_live += process->nbr_live;
			process->nbr_live = 0;
		}
		process = process->next;
	}
	if (nbr == *nbr_live)
		return (true);
	return (false);
}

static t_bool			set_cycle_to_die(t_battle *battle, int nbr_live)
{
	static int		check = 0;

	++check;
	if (nbr_live >= NBR_LIVE || check >= MAX_CHECKS)
	{
		if (battle->cycle_to_die >= CYCLE_DELTA)
			battle->cycle_to_die -= CYCLE_DELTA;
		else
			battle->cycle_to_die = 0;
		check = 0;
	}
	if (nbr_live == 0)
		return (true);
	return (false);
}

/*
 * ** If all process of every champions are dead, return true.
 * ** Otherwise, return false.
 * */
t_bool					is_dead(t_battle *battle)
{
	int				i;
	int				nbr_live;
	static int		dead = 1;

	nbr_live = 0;
	i = 0;
	while (battle->champion[i] != NULL)
	{
		if (kill_dead_process(&battle->champion[i]->process, &nbr_live)
				&& battle->champion[i]->is_dead == -1)
			battle->champion[i]->is_dead = dead++;
		else
			battle->champion[i]->is_dead = -1;
		++i;
	}
	return (set_cycle_to_die(battle, nbr_live));
}
