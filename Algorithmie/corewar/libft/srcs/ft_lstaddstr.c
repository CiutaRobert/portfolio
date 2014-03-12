/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:29:58 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/06 21:02:25 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This functions creates a new link which contains the given null terminated
** string, and then appends it at the top of the list pointed by alst.
*/
int		ft_lstaddstr(t_list **alst, char *str)
{
	return (ft_lstaddnew(alst, str, (ft_strlen(str) + 1)));
}
