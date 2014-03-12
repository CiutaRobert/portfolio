/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 19:43:02 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 18:57:09 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ops_core.h"

t_bool			ft_aff(t_battle *battle, t_op *op, t_u16 pc)
{
	t_u8		byte_coding;
	t_u32		*reg;

	(void)pc;
	if ((byte_coding = get_byte_coding(battle, op)) == 0)
		return (false);
	if ((reg = get_register(battle)) == NULL)
		return (false);
	print_ihm("%c", (char)*reg);
	return (true);
}
