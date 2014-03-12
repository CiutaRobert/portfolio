/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 19:42:42 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 21:24:05 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ops_core.h"

static t_bool	set_idx(t_battle *battle, t_u16 pc, t_u8 pcode, int *idx)
{
	t_u32		*reg_ptr;

	if ((pcode & IND_CODE) == IND_CODE)
		*idx = (int)get_indirect(battle, pc, IDX_MOD);
	else if (pcode & DIR_CODE)
		*idx = (int)vm_memget16(battle);
	else if (pcode & REG_CODE)
	{
		reg_ptr = get_register(battle);
		if (reg_ptr == NULL)
			return (false);
		*idx = (int)*reg_ptr;
	}
	return (true);
}

t_bool			ft_sti(t_battle *battle, t_op *op, t_u16 pc)
{
	t_u8		byte_coding;
	t_u32		*reg;
	int			idx1;
	int			idx2;

	if ((byte_coding = get_byte_coding(battle, op)) == 0)
		return (false);
	if ((reg = get_register(battle)) == NULL)
		return (false);
	if (set_idx(battle, pc, byte_code_arg(byte_coding, 1), &idx1) == false)
		return (false);
	if ((byte_code_arg(byte_coding, 2) & IND_CODE) == IND_CODE)
		return (false);
	if (set_idx(battle, pc, byte_code_arg(byte_coding, 2), &idx2) == false)
		return (false);
	vm_write(battle, (pc + ((idx1 + idx2) % IDX_MOD)), (t_u8*)reg, REG_SIZE);
	return (true);
}
