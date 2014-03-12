/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 22:30:13 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/10 22:31:24 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **begin_list)
{
	t_list	*swap;
	t_list	*reverse;

	reverse = NULL;
	while (*begin_list != NULL)
	{
		swap = (*begin_list)->next;
		(*begin_list)->next = reverse;
		reverse = *begin_list;
		*begin_list = swap;
	}
	*begin_list = reverse;
}
