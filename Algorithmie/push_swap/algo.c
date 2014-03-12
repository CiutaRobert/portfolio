/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 13:43:02 by cvxfous           #+#    #+#             */
/*   Updated: 2013/12/29 16:28:18 by cvxfous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int	get_min(t_list *list)
{
	t_elem	*tmp;
	int		min;

	if (!list->elems)
		return (-42);
	min = list->elems->val;
	tmp = list->elems->next;
	while (tmp != list->elems)
	{
		if (min > tmp->val)
			min = tmp->val;
		tmp = tmp->next;
	}
	return (min);
}

static int	is_sort(t_list *list)
{
	int		flag;
	int		prev;
	t_elem	*tmp;

	if (!list->elems)
		return (0);
	flag = 0;
	tmp = list->elems->prev;
	prev = list->elems->val;
	while (tmp != list->elems)
	{
		if (!flag)
			tmp = list->elems;
		flag = 1;
		if (tmp->val < prev)
			return (0);
		prev = tmp->val;
		tmp = tmp->next;
	}
	return (1);
}

static void	empty_list(t_list *l_a, t_list *l_b)
{
	while (l_b->elems)
	{
		ft_putstr(" pa");
		l_a->push_front(l_a, l_b->elems->val);
		l_b->pop(l_b);
	}
	ft_putstr("\n");
}

void		push_swap(t_list *l_a, t_list *l_b)
{
	int		flag;
	int		min;
	t_elem	*tmp;

	min = get_min(l_a);
	flag = 0;
	while (l_a->elems && !is_sort(l_a))
	{
		if (flag)
			ft_putstr(" ");
		flag = 1;
		tmp = l_a->elems;
		if (tmp->val == min)
		{
			ft_putstr("pb");
			l_b->push_front(l_b, tmp->val);
			l_a->pop(l_a);
			min = get_min(l_a);
		}
		else
			l_a->shift(l_a);
	}
	empty_list(l_a, l_b);
}
