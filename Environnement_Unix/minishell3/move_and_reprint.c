/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_reprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 02:19:13 by cvxfous           #+#    #+#             */
/*   Updated: 2014/02/09 04:25:53 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<term.h>
#include	"ft_sh.h"

void		reprint_line(t_all *all)
{
	int		i;
	int		len;

	i = all->cursor_x + 1;
	while (--i > 0)
		tputs(all->caps[MOVE_LEFT], 1, ft_putchar);
	tputs(all->caps[CLEAR_EOL], 1, ft_putchar);
	ft_putstr(all->line);
	len = ft_strlen(all->line) - 1;
	i = -1;
	while (++i + all->cursor_x < len)
		tputs(all->caps[MOVE_LEFT], 1, ft_putchar);
}

void		insert_char(t_all *all, char c)
{
	int		i;

	i = BUFF_SIZE;
	while (--i > 0)
	{
		if (i >= all->cursor_x)
			all->line[i] = all->line[i - 1];
	}
	all->line[all->cursor_x] = c;
	reprint_line(all);
	++all->cursor_x;
}

void		go_start(t_all *all)
{
	while (all->cursor_x > 0)
	{
		--all->cursor_x;
		tputs(all->caps[MOVE_LEFT], 1, ft_putchar);
	}
}

void		go_end(t_all *all)
{
	int		len;

	len = ft_strlen(all->line);
	while (all->cursor_x < len)
	{
		++all->cursor_x;
		tputs(all->caps[MOVE_RIGHT], 1, ft_putchar);
	}
}
