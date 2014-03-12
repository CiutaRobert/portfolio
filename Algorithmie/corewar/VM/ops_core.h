/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_core.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 20:26:35 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 20:00:33 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_CORE_H
# define OPS_CORE_H

# include "VM.h"

# define vm_memget8(_b) (*(t_u8*)vm_memget(_b, 1))
# define vm_memget16(_b) (*(t_u16*)vm_memget(_b, 2))
# define vm_memget32(_b) (*(t_u32*)vm_memget(_b, 4))

# define vm_read8(_b, _i) (*(t_u8*)vm_read(_b, _i, 1))
# define vm_read16(_b, _i) (*(t_u16*)vm_read(_b, _i, 2))
# define vm_read32(_b, _i) ((t_u32)*vm_read(_b, _i, 4))

# define byte_code_arg(_b, _i) (_b >> (8 - ((_i + 1) * 2)))

/*
** ops_core.c
*/
void			*vm_memcpy(void *s1, const void *s2, size_t n);
t_u32			*vm_memget(t_battle *battle, size_t size);
t_u32			*vm_read(t_battle *battle, t_u16 idx, size_t size);
void			vm_write(t_battle *battle, short idx, t_u8 *data, size_t size);
t_u8			get_byte_coding(t_battle *battle, t_op *op);
t_uint			*get_register(t_battle *battle);
t_u32			get_indirect(t_battle *battle, t_u16 pc, int flag);

#endif /* !OPS_CORE_H */
