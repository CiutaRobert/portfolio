/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:03:03 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/12 22:03:03 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<term.h>
#include	<stdlib.h>
#include	"ft_select.h"

static void	lst_init(t_all *all, t_dbl *pos)
{
	tputs(all->opt[TERM_END], 1, ft_putchar2);
	tputs(all->opt[TERM_INIT], 1, ft_putchar2);
	tputs(tgoto(all->opt[CURSOR_MOVE], 0, 0), 1, ft_putchar2);
	pos->y = all->full->idx;
}

static char	*lst_is_error(t_all *all, t_dbl *pos)
{
	if ((pos->x += 20) > all->column)
	{
		ft_putstr_fd(all->fd, "Error!");
		return (NULL);
	}
	return (OK);
}

char		*lst_check_error(t_all *all, t_dbl *pos)
{
	int		flag;
	t_list	*tmp;
	t_list	*right;

	lst_init(all, pos);
	flag = 0;
	tmp = all->full->prev;
	while ((tmp != all->full || !flag) && flag < all->line)
	{
		pos->x = 0;
		if (lst_is_error(all, pos) == NULL)
			return (NULL);
		tmp = (!flag++ ? all->full : tmp);
		while ((right = lst_right(all, pos)))
		{
			if (lst_is_error(all, pos) == NULL)
				return (NULL);
			pos->y = right->idx;
		}
		pos->y = tmp->next->idx;
	}
	pos->y = all->full->idx;
	return (OK);
}
