/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 19:42:21 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 20:58:40 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ops_core.h"

static t_bool	set_val(t_battle *battle, t_u16 pc, t_u8 pcode, t_u32 *val)
{
	t_u32		*reg_ptr;

	if ((pcode & IND_CODE) == IND_CODE)
		*val = get_indirect(battle, pc, IDX_MOD);
	else if (pcode & DIR_CODE)
		*val = vm_memget32(battle);
	else if (pcode & REG_CODE)
	{
		reg_ptr = get_register(battle);
		if (reg_ptr == NULL)
			return (false);
		*val = *reg_ptr;
	}
	return (true);
}

t_bool			ft_or(t_battle *battle, t_op *op, t_u16 pc)
{
	t_u8		byte_coding;
	t_u32		arg0;
	t_u32		arg1;
	t_u32		*dst_reg;

	if ((byte_coding = get_byte_coding(battle, op)) == 0)
		return (false);
	if (set_val(battle, pc, byte_code_arg(byte_coding, 0), &arg0) == false)
		return (false);
	if (set_val(battle, pc, byte_code_arg(byte_coding, 1), &arg1) == false)
		return (false);
	if ((dst_reg = get_register(battle)) == NULL)
		return (false);
	*dst_reg = arg0 | arg1;
	if (*dst_reg)
		battle->curr_process->carry = 0;
	else
		battle->curr_process->carry = 1;
	return (true);
}
