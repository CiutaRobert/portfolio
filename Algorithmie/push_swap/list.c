/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 01:27:37 by cvxfous           #+#    #+#             */
/*   Updated: 2013/12/29 16:57:08 by cvxfous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"push_swap.h"

static void	lst_push_back(void *list, int val)
{
	t_elem	*new;
	t_list	*this;

	this = (t_list *)list;
	if ((new = (t_elem *)malloc(sizeof(t_elem))) == NULL)
		return ;
	new->val = val;
	new->next = new;
	new->prev = new;
	if (this->elems)
	{
		new->next = this->elems;
		new->prev = this->elems->prev;
		this->elems->prev->next = new;
		this->elems->prev = new;
	}
	else
		this->elems = new;
}

static void	lst_push_front(void *list, int val)
{
	t_list	*this;

	this = (t_list *)list;
	lst_push_back(list, val);
	this->elems = this->elems->prev;
}

static void	lst_pop(void *list)
{
	t_list	*this;
	t_elem	*tmp;

	this = (t_list *)list;
	if (!this->elems)
		return ;
	if (this->elems == this->elems->next)
	{
		free(this->elems);
		this->elems = NULL;
	}
	else
	{
		tmp = this->elems;
		this->elems->prev->next = this->elems->next;
		this->elems->next->prev = this->elems->prev;
		this->elems = this->elems->next;
		free(tmp);
	}
}

static void	lst_shift(void *list)
{
	t_list	*this;

	ft_putstr("ra");
	this = (t_list *)list;
	if (!this->elems)
		return ;
	this->elems = this->elems->next;
}

t_list		*create_list(void)
{
	t_list	*list;

	if ((list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->push_back = &lst_push_back;
	list->push_front = &lst_push_front;
	list->pop = &lst_pop;
	list->shift = &lst_shift;
	list->elems = NULL;
	return (list);
}
