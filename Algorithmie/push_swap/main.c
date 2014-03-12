/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/24 02:16:32 by cvxfous           #+#    #+#             */
/*   Updated: 2013/12/29 14:41:23 by cvxfous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"push_swap.h"

void		free_list(t_list *list)
{
	int		flag;
	t_elem	*tmp;
	t_elem	*tmp2;

	flag = 0;
	if (list->elems)
	{
		tmp = list->elems->prev;
		while (tmp != list->elems)
		{
			if (!flag)
				tmp = list->elems;
			flag = 1;
			tmp2 = tmp;
			tmp = tmp->next;
			free(tmp2);
		}
	}
	free(list);
}

int			main(int ac, char **av)
{
	int		i;
	t_list	*l_a;
	t_list	*l_b;

	if (ac < 3)
	{
		ft_putstr("\n");
		return (0);
	}
	l_a = create_list();
	l_b = create_list();
	i = 0;
	while (++i < ac)
		l_a->push_back(l_a, ft_atoi(av[i]));
	push_swap(l_a, l_b);
	free_list(l_a);
	free_list(l_b);
	return (0);
}
