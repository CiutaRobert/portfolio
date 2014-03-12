/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 03:47:34 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/09 04:32:18 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<term.h>
#include	"ft_sh.h"

static void	search_history(t_all *all)
{
	int		i;
	t_list	*tmp;

	tmp = all->list;
	i = 0;
	while (tmp)
	{
		if (i == all->cursor_y)
		{
			go_start(all);
			ft_strcpy(tmp->str, all->line);
			all->line[ft_strlen(tmp->str)] = 0;
			reprint_line(all);
			tputs(all->caps[MOVE_LEFT], 1, ft_putchar);
			go_end(all);
		}
		tmp = tmp->next;
		++i;
	}
}

void		history_prev(t_all *all)
{
	if (!all->cursor_y)
		return ;
	--all->cursor_y;
	search_history(all);
}

void		history_next(t_all *all)
{
	++all->cursor_y;
	if (all->cursor_y == all->max_y)
	{
		go_start(all);
		all->line[0] = 0;
		reprint_line(all);
		return ;
	}
	if (all->cursor_y > all->max_y)
		all->cursor_y = all->max_y;
	else
		search_history(all);
}
