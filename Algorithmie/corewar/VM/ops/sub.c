/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 19:42:14 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 11:21:02 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ops_core.h"

t_bool			ft_sub(t_battle *battle, t_op *op, t_u16 pc)
{
	t_uint		byte_coding;
	t_uint		*r1;
	t_uint		*r2;
	t_uint		*r3;

	(void)pc;
	if ((byte_coding = get_byte_coding(battle, op)) == 0)
		return (false);
	if ((r1 = get_register(battle)) == NULL)
		return (false);
	if ((r2 = get_register(battle)) == NULL)
		return (false);
	if ((r3 = get_register(battle)) == NULL)
		return (false);
	*r3 = *r1 - *r2;
	if (*r3)
		battle->curr_process->carry = 0;
	else
		battle->curr_process->carry = 1;
	return (true);
}
