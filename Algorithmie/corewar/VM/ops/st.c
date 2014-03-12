/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 19:42:02 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 19:09:06 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ops_core.h"

t_bool			ft_st(t_battle *battle, t_op *op, t_u16 pc)
{
	t_u8		byte_coding;
	t_u32		*src_reg;
	short		ind_idx;
	t_u32		*dst_reg;

	if ((byte_coding = get_byte_coding(battle, op)) == 0)
		return (false);
	if ((src_reg = get_register(battle)) == NULL)
		return (false);
	if ((byte_code_arg(byte_coding, 1) & IND_CODE) == IND_CODE)
	{
		ind_idx = (short)vm_memget16(battle);
		ind_idx %= IDX_MOD;
		vm_write(battle, pc + ind_idx, (t_u8*)src_reg, 4);
	}
	else
	{
		if ((dst_reg = get_register(battle)) == NULL)
			return (false);
		*dst_reg = *src_reg;
	}
	return (true);
}
