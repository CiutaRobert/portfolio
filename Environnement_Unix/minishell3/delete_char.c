/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 14:43:18 by cvxfous           #+#    #+#             */
/*   Updated: 2014/02/07 14:56:29 by cvxfous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<term.h>
#include	"ft_sh.h"

void		del_char(t_all *all)
{
	int		i;

	i = -1;
	while (++i + 1 < BUFF_SIZE)
	{
		if (i >= all->cursor_x)
			all->line[i] = all->line[i + 1];
	}
	all->line[BUFF_SIZE - 1] = 0;
	reprint_line(all);
	if (ft_strlen(all->line) != all->cursor_x)
		tputs(all->caps[MOVE_LEFT], 1, ft_putchar);
}

void		del_prev_char(t_all *all)
{
	if (!all->cursor_x)
		return ;
	move_cursor_left(all);
	del_char(all);
}
