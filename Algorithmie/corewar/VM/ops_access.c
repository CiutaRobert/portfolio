/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_access.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 22:03:27 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 21:36:36 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops_core.h"

static t_bool	check_bit_couple(t_u8 byte, t_op *op, int i)
{
	if ((byte & IND_CODE) == IND_CODE)
	{
		if (!op->argv[i] & T_IND)
			return (0);
		return (1);
	}
	if ((byte & DIR_CODE) == DIR_CODE)
	{
		if (!op->argv[i] & T_DIR)
			return (0);
		return (1);
	}
	if ((byte & REG_CODE) == REG_CODE)
	{
		if (!op->argv[i] & T_REG)
			return (0);
		return (1);
	}
	return (0);
}

t_u8			get_byte_coding(t_battle *battle, t_op *op)
{
	t_u8		code;
	t_u8		tmp;
	int			i;

	code = vm_memget8(battle);
	if ((t_u8)(code << (op->argc << 1)) != (t_u8)0)
		return (0);
	tmp = code >> (8 - (op->argc << 1));
	i = op->argc;
	while (i--)
	{
		if (check_bit_couple(tmp, op, i) == false)
			return (0);
		tmp >>= 2;
	}
	return (code);
}

t_u32			*get_register(t_battle *battle)
{
	t_uint		reg_idx;

	reg_idx = vm_memget8(battle);
	if (reg_idx < 1 || reg_idx > REG_NUMBER)
		return (NULL);
	return (&battle->curr_process->reg[reg_idx - 1]);
}

t_u32			get_indirect(t_battle *battle, t_u16 pc, int flag)
{
	short		mem_idx;
	t_u32		value;

	mem_idx = (short)vm_memget16(battle);
	while (mem_idx < 0)
		mem_idx = MEM_SIZE + mem_idx;
	if (flag == IDX_MOD)
		mem_idx %= IDX_MOD;
	value = vm_read32(battle, pc + mem_idx);
	return (value);
}
