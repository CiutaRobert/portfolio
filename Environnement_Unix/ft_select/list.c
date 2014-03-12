/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:02:52 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/12 22:02:52 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		"ft_select.h"

static t_list	*lst_new(char *str, int idx)
{
	t_list		*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->str = str;
	new->len = ft_strlen(str);
	new->idx = idx;
	new->is_cur = 0;
	new->is_select = 0;
	new->prev = new;
	new->next = new;
	return (new);
}

void			lst_push_back(t_list **list, char *str, int idx)
{
	t_list		*new;

	if ((new = lst_new(str, idx)) == NULL)
		return ;
	if (!*list)
	{
		new->is_cur = 1;
		*list = new;
		return ;
	}
	new->next = *list;
	new->prev = (*list)->prev;
	(*list)->prev->next = new;
	(*list)->prev = new;
}

int				lst_is_inside(t_list *list, int idx)
{
	int			flag;
	t_list		*tmp;

	flag = 0;
	tmp = list->prev;
	while ((tmp != list) || !flag)
	{
		if (!flag++)
			tmp = list;
		if (idx == tmp->idx)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_list			*lst_right(t_all *all, t_dbl *pos)
{
	int			i;
	t_list		*tmp;

	i = 0;
	tmp = all->full;
	while (tmp->idx != pos->y && ++i)
		tmp = tmp->next;
	if (i + all->line > all->last_elem)
		return (NULL);
	i = -1;
	while (++i < all->line)
		tmp = tmp->next;
	return (tmp);
}

t_list			*lst_left(t_all *all, t_dbl *pos)
{
	int			i;
	t_list		*tmp;

	i = 0;
	tmp = all->full;
	while (tmp->idx != pos->y && ++i)
		tmp = tmp->next;
	if (i - all->line < 0)
		return (NULL);
	i = -1;
	while (++i < all->line)
		tmp = tmp->prev;
	return (tmp);
}
