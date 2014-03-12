/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 18:19:13 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 19:34:05 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ops_core.h"
#include "../VM.h"

t_bool          ft_live(t_battle *battle, t_op *op, t_u16 pc)
{
	int			i;
	char		*name;
	t_u32		id;

	(void)op;
	(void)pc;
	id = vm_memget32(battle);
	i = 0;
	name = "unknown";
	while (battle->champion[i] != NULL)
	{
		if ((t_u32)battle->champion[i]->id == id)
		{
			name = battle->champion[i]->header.prog_name;
			battle->curr_process->nbr_live++;
			battle->curr_champion->is_dead = 0;
		}
		++i;
	}
	print_ihm("un processus dit que le joueur %d(%s) est en vie\n", id, name);
	return (true);
}
