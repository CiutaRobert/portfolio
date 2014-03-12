/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:00:49 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/09 03:47:24 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<term.h>
#include	"ft_sh.h"

void		move_cursor_left(t_all *all)
{
	if (all->cursor_x <= 0)
		return ;
	tputs(all->caps[MOVE_LEFT], 1, ft_putchar);
	--all->cursor_x;
}

static void	move_cursor_right(t_all *all)
{
	if (all->cursor_x >= BUFF_SIZE || all->cursor_x >= ft_strlen(all->line))
		return ;
	tputs(all->caps[MOVE_RIGHT], 1, ft_putchar);
	++all->cursor_x;
}

static void	move_word_left(t_all *all)
{
	int		i;

	i = all->cursor_x + 1;
	while (--i > 0 && all->line[i] && all->line[i] != ' ')
		move_cursor_left(all);
	++i;
	while (--i > 0 && (!all->line[i] || all->line[i] == ' '))
		move_cursor_left(all);
	++i;
	while (--i > 0 && all->line[i] != ' ')
		move_cursor_left(all);
	if (i)
		move_cursor_right(all);
}

static void	move_word_right(t_all *all)
{
	int		i;

	i = all->cursor_x - 1;
	while (all->line[++i] && all->line[i] != ' ')
		move_cursor_right(all);
	--i;
	while (all->line[++i] && all->line[i] == ' ')
		move_cursor_right(all);
}

void		handle_cursor(t_all *all, char *buf)
{
	if (buf[1] == 91)
	{
		if (buf[2] == 65)
			history_prev(all);
		else if (buf[2] == 66)
			history_next(all);
		else if (buf[2] == 67)
			move_cursor_right(all);
		else if (buf[2] == 68)
			move_cursor_left(all);
	}
	else if (buf[1] == 27 && buf[2] == 91)
	{
		if (buf[3] == 67)
			move_word_right(all);
		else if (buf[3] == 68)
			move_word_left(all);
	}
}
