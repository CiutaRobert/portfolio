/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdupone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 09:50:44 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 15:54:58 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a fresh copy of the given link with next set to NULL
*/
t_list		*ft_lstdupone(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	return (ft_lstnew(lst->data, lst->size));
}
