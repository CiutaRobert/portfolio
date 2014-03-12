/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 21:14:40 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 15:56:21 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		default_cmp_function(void *ptr1, void *ptr2)
{
	char		*str1;
	char		*str2;

	str1 = (char*)ptr1;
	str2 = (char*)ptr2;
	return (ft_strcmp(str1, str2));
}

static void		swap_links(t_list *l1, t_list *l2)
{
	void		*tmp_data;
	size_t		tmp_size;

	tmp_data = l1->data;
	tmp_size = l1->size;
	l1->data = l2->data;
	l1->size = l2->size;
	l2->data = tmp_data;
	l2->size = tmp_size;
}

void			ft_lstsort(t_list *begin, int (*cmp)(void *, void *))
{
	t_list		*link;
	int			sorted;

	if (begin == NULL)
		return ;
	if (cmp == NULL)
		cmp = default_cmp_function;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		link = begin;
		while (link->next)
		{
			if (cmp(link->data, link->next->data) > 0)
			{
				swap_links(link, link->next);
				sorted = 0;
			}
			link = link->next;
		}
	}
}
