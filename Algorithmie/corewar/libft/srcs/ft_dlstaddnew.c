/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 18:24:16 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/08 17:12:25 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dlstaddnew(t_dlist **alst, const void *data, size_t size)
{
	t_dlist		*new;

	if ((new = ft_dlstnew(data, size)) == NULL)
		return (0);
	ft_dlstadd(alst, new);
	return (1);
}
