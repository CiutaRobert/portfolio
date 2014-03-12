/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 00:02:08 by cvxfous           #+#    #+#             */
/*   Updated: 2014/01/29 18:22:53 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdlib.h>
#include		<corewar_asm.h>

static t_list	*lst_new(char *str)
{
	t_list		*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->str = str;
	new->next = NULL;
	return (new);
}

static t_labl	*lbl_new(char *str, int len, int addr)
{
	t_labl		*new;

	if ((new = (t_labl *)malloc(sizeof(t_labl))) == NULL)
		return (NULL);
	new->str = str;
	new->len = len;
	new->addr = addr;
	new->next = NULL;
	return (new);
}

void			lst_pushback(t_list **list, char *str)
{
	t_list		*new;
	t_list		*tmp;

	if ((new = lst_new(str)) == NULL)
		return ;
	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void			lbl_pushback(t_labl **list, char *str, int len, int addr)
{
	t_labl		*new;
	t_labl		*tmp;

	if ((new = lbl_new(str, len, addr)) == NULL)
		return ;
	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
