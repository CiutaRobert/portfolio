/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:23:00 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 15:53:23 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds the given data of size as a new link to the top of *lst
** If the new link fails to be created, 0 is returned. Otherwise, 1 is returned
*/
int		ft_lstaddnew(t_list **alst, void const *data, size_t size)
{
	t_list		*new;

	new = ft_lstnew(data, size);
	if (new == NULL)
		return (0);
	ft_lstadd(alst, new);
	return (1);
}
