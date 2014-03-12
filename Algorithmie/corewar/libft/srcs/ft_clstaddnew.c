/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstaddnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 19:21:44 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/08 17:52:10 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_clstaddnew(t_clist **alst, const void *data, size_t size)
{
	t_clist		*new;

	if ((new = ft_clstnew(data, size)) == NULL)
		return (0);
	ft_clstadd(alst, new);
	return (1);
}
