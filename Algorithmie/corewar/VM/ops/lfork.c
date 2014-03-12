/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 19:42:51 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 14:00:19 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ops_core.h"

t_bool			ft_lfork(t_battle *battle, t_op *op, t_u16 pc)
{
	short			addr;
	t_process		*father;
	t_process		*child;

	(void)op;
	addr = (short)vm_memget16(battle);
	father = battle->curr_process;
	child = (t_process*)ft_memdup((t_process*)father, sizeof(t_process));
	child->next = NULL;
	child->pc = &battle->memory[(pc + addr) % MEM_SIZE];
	child->nbr_live = 0;
	while (father->next != NULL)
		father = father->next;
	father->next = child;
	child->prev = father;
	return (true);
}
