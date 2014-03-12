/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 21:23:26 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 22:48:20 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "VM.h"
#include "ops_core.h"

static t_event	evt[] = {
	{ "live",  ft_live },
	{ "ld",    ft_ld },
	{ "st",    ft_st },
	{ "add",   ft_add },
	{ "sub",   ft_sub },
	{ "and",   ft_and },
	{ "or",    ft_or },
	{ "xor",   ft_xor },
	{ "zjmp",  ft_zjmp },
	{ "ldi",   ft_ldi },
	{ "sti",   ft_sti },
	{ "fork",  ft_fork },
	{ "lld",   ft_lld },
	{ "lldi",  ft_lldi },
	{ "lfork", ft_lfork },
	{ "aff",   ft_aff },
	{ NULL, NULL }
};

/*
** Get op consumption.
*/
t_uint			get_op_consumption(t_process *process)
{
	t_uint		i;
	t_u8		code;

	i = 0;
	code = (t_u8)*process->pc;
	while (op_tab[i].label != NULL)
	{
		if (op_tab[i].opcode == code)
			return (op_tab[i].consumption);
		++i;
	}
	process = process->next;
	return (1);
}

static t_op		*get_op(t_battle *battle)
{
	t_uint	i;
	t_u8	code;

	i = 0;
	code = vm_memget8(battle);
	while (op_tab[i].label != NULL)
	{
		if (op_tab[i].opcode == code)
			return (&op_tab[i]);
		++i;
	}
	return (NULL);
}

static t_uint	exec_op(t_battle *battle, t_op *op, t_u16 pc)
{
	t_uint	i;
	char	*pc_save;

	i = 0;
	while (evt[i].name != NULL)
	{
		if (ft_strcmp(evt[i].name, op->label) == 0)
		{
			if (battle->dump != 0
					&& battle->cycle + op->consumption >= (t_ulong)battle->dump)
				return (battle->dump);
			pc_save = battle->curr_process->pc;
			if (evt[i].fn(battle, op, pc) == true)
				return (op->consumption);
			else
				print_ihm("illegal corewar instruction\n");
			battle->curr_process->carry = 0;
			battle->curr_process->pc = pc_save;
			return (1);
		}
		++i;
	}
	return (1);
}

/*
** battle->curr_champion and battle->curr_process must be set before call
** this function
*/
t_uint			execute_op(t_battle *battle)
{
	t_op	*op;
	t_u16	pc;

	pc = battle->curr_process->pc - battle->memory;
	op = get_op(battle);
	if (op == NULL)
		return (1);
	return (exec_op(battle, op, pc));
}
