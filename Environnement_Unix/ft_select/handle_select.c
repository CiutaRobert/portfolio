/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_select.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:02:57 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/12 22:02:58 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_select.h"

void		handle_select(t_all *all, t_list **choice, t_dbl *pos)
{
	t_list	*tmp;

	tmp = all->full;
	while (tmp->idx != pos->y)
		tmp = tmp->next;
	tmp->is_select ^= 1;
	if (tmp->is_select)
		lst_push_back(choice, tmp->str, pos->y);
	else
		lst_del(choice, pos->y);
	ft_cursor_down(all, pos);
}
