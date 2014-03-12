/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 19:42:35 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 21:10:16 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ops_core.h"

t_bool			ft_zjmp(t_battle *battle, t_op *op, t_u16 pc)
{
	short		addr;

	(void)op;
	addr = (short)vm_memget16(battle) % IDX_MOD;
	if (battle->curr_process->carry == 0)
		return (true);
	battle->curr_process->pc = &battle->memory[(pc + addr) % MEM_SIZE];
	battle->curr_process->carry = 1;
	return (true);
}
