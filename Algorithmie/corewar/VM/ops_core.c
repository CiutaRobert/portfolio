/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 22:02:54 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 19:33:58 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops_core.h"

void			*vm_memcpy(void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		*((char*)((long)s1 % MEM_SIZE)) = *((char*)((long)s2 % MEM_SIZE));
		s1++;
		s2++;
	}
	return (s1);
}

t_u32			*vm_memget(t_battle *battle, size_t size)
{
	int				i;
	static t_u8		memspace[4];

	i = size - 1;
	while (i >= 0)
	{
		if (battle->curr_process->pc == &battle->memory[MEM_SIZE])
			battle->curr_process->pc = &battle->memory[0];
		memspace[i] = *(battle->curr_process->pc);
		(battle->curr_process->pc)++;
		--i;
	}
	if (battle->curr_process->pc == &battle->memory[MEM_SIZE])
		battle->curr_process->pc = &battle->memory[0];
	return ((t_u32*)memspace);
}

t_u32			*vm_read(t_battle *battle, t_u16 idx, size_t size)
{
	t_uint			i;
	static t_u8		memspace[4];

	i = 0;
	while (i < size)
	{
		memspace[i] = (t_u8)battle->memory[(idx + i) % MEM_SIZE];
		i++;
	}
	return ((t_u32*)memspace);
}

void			vm_write(t_battle *battle, short idx, t_u8 *data, size_t size)
{
	int			i;
	t_u8		*cpy;

	cpy = malloc(sizeof(t_u8) * size);
	i = size - 1;
	while (i >= 0)
	{
		cpy[i] = *data++;
		--i;
	}
	i = 0;
	while (idx < 0)
		idx = MEM_SIZE + idx;
	while ((size_t)i < size)
	{
		battle->memory[idx % MEM_SIZE] = cpy[i];
		battle->belongs[idx % MEM_SIZE] = battle->curr_champion->id;
		idx++;
		i++;
	}
	free(cpy);
}
