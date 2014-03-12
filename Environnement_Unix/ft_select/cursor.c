/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:00:49 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/12 22:00:49 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<term.h>
#include	"ft_select.h"

static void	ft_cursor_up(t_all *all, t_dbl *pos)
{
	t_list	*tmp;

	tmp = all->full;
	while (tmp->idx != pos->y)
		tmp = tmp->next;
	tmp->is_cur = 0;
	tmp->prev->is_cur = 1;
	pos->y = tmp->prev->idx;
}

void		ft_cursor_down(t_all *all, t_dbl *pos)
{
	t_list	*tmp;

	tmp = all->full;
	while (tmp->idx != pos->y)
		tmp = tmp->next;
	tmp->is_cur = 0;
	tmp->next->is_cur = 1;
	pos->y = tmp->next->idx;
}

void		ft_cursor_right(t_all *all, t_dbl *pos)
{
	int		i;
	t_list	*tmp;

	if (pos->y + all->line > all->last_elem)
	{
		ft_cursor_down(all, pos);
		while (lst_left(all, pos))
			ft_cursor_left(all, pos);
		return ;
	}
	tmp = all->full;
	while (tmp->idx != pos->y)
		tmp = tmp->next;
	tmp->is_cur = 0;
	i = -1;
	while (++i != all->line)
		tmp = tmp->next;
	tmp->is_cur = 1;
	pos->y = tmp->idx;
}

void		ft_cursor_left(t_all *all, t_dbl *pos)
{
	int		i;
	t_list	*tmp;

	if (pos->y - all->line < 0)
	{
		ft_cursor_up(all, pos);
		while (lst_right(all, pos))
			ft_cursor_right(all, pos);
		return ;
	}
	tmp = all->full;
	while (tmp->idx != pos->y)
		tmp = tmp->next;
	tmp->is_cur = 0;
	i = -1;
	while (++i != all->line)
		tmp = tmp->prev;
	tmp->is_cur = 1;
	pos->y = tmp->idx;
}

void		handle_cursor(t_all *all, t_dbl *pos, char dir)
{
	int		i;
	void	(*ptr[4])(t_all *, t_dbl *) = {&ft_cursor_up, &ft_cursor_down,
										&ft_cursor_right, &ft_cursor_left};

	i = -1;
	while (++i < 4)
	{
		if (dir == 65 + i)
			(*ptr[i])(all, pos);
	}
}
