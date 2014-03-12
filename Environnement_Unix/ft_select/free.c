/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:03:11 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/12 22:03:12 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"ft_select.h"

void		lst_del(t_list **list, int idx)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*list)
		return ;
	if (*list == (*list)->next)
	{
		free(*list);
		*list = NULL;
	}
	else
	{
		tmp = *list;
		while (tmp->idx != idx)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		if ((*list)->idx == idx)
			*list = tmp2;
		free(tmp);
	}
}

void		lst_free(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (*list != NULL)
	{
		tmp = tmp->next;
		lst_del(list, tmp->prev->idx);
	}
}
