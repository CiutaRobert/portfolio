/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:01:43 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/12 22:01:44 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<term.h>
#include	<stdlib.h>
#include	"ft_select.h"

static void	lst_aff_padding(t_list *elem)
{
	int		i;
	int		space;

	space = 20 - elem->len;
	i = -1;
	while (++i < space)
		ft_putchar2(' ');
}

static void	lst_aff_elem(t_all *all, t_list *tmp, t_dbl *pos)
{
	if (tmp->is_cur)
		tputs(all->opt[UNDERLINE_ON], 1, ft_putchar2);
	if (tmp->is_select)
		tputs(all->opt[INVERTVIDEO_ON], 1, ft_putchar2);
	ft_putstr_fd(all->fd, tmp->str);
	if (tmp->is_select)
		tputs(all->opt[INVERTVIDEO_OFF], 1, ft_putchar2);
	if (tmp->is_cur)
		tputs(all->opt[UNDERLINE_OFF], 1, ft_putchar2);
	if (lst_right(all, pos))
		lst_aff_padding(tmp);
}

static void	lst_aff_elem_right(t_all *all, t_list *right, t_dbl *pos)
{
	pos->y = right->idx;
	lst_aff_elem(all, right, pos);
}

void		lst_aff(t_all *all)
{
	int		flag;
	t_dbl	pos;
	t_list	*tmp;
	t_list	*right;

	if (lst_check_error(all, &pos) == NULL)
		return ;
	flag = 0;
	tmp = all->full->prev;
	while ((tmp != all->full || !flag) && flag < all->line)
	{
		tmp = (!flag++ ? all->full : tmp);
		lst_aff_elem(all, tmp, &pos);
		while ((right = lst_right(all, &pos)))
			lst_aff_elem_right(all, right, &pos);
		pos.y = tmp->next->idx;
		if (flag < all->line)
			ft_putchar2('\n');
		tmp = tmp->next;
	}
}
