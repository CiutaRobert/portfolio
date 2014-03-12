/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 19:42:39 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 21:21:46 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ops_core.h"

/*
** TODO:
** ld, lld, and lldi change the carry;
** for ldi, it is not precised, so, do that instruction changes the carry
** or no ???
*/
static t_bool	set_idx(t_battle *battle, t_u16 pc, t_u8 pcode, t_u32 *idx)
{
	t_u32		*reg_ptr;

	if ((pcode & IND_CODE) == IND_CODE)
		*idx = get_indirect(battle, pc, IDX_MOD);
	else if (pcode & DIR_CODE)
		*idx = (t_u32)vm_memget16(battle);
	else if (pcode & REG_CODE)
	{
		reg_ptr = get_register(battle);
		if (reg_ptr == NULL)
			return (false);
		*idx = *reg_ptr;
	}
	return (true);
}

t_bool			ft_ldi(t_battle *battle, t_op *op, t_u16 pc)
{
	t_u8		byte_coding;
	t_u32		idx0;
	t_u32		idx1;
	t_u32		*reg;

	if ((byte_coding = get_byte_coding(battle, op)) == 0)
		return (false);
	if (set_idx(battle, pc, byte_code_arg(byte_coding, 0), &idx0) == false)
		return (false);
	if ((byte_code_arg(byte_coding, 1) & IND_CODE) == IND_CODE)
		return (false);
	if (set_idx(battle, pc, byte_code_arg(byte_coding, 1), &idx1) == false)
		return (false);
	if ((reg = get_register(battle)) == NULL)
		return (false);
	*reg = (idx0 + idx1) % IDX_MOD;
	return (true);
}
