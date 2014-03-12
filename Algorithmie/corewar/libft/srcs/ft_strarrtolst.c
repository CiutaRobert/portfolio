/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrtolst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 13:29:26 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/10 22:39:43 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Convert the argv array (which may contain null terminated strings)
**   into a t_list links string.
** - The address of the first link is returned.
** - If a negative value is given as argc, it is assumed that the array
**   argc terminates with a NULL pointer, and ft_arlen() is then used
**   to determine argc (array size).
** - It any link creation fails, NULL is returned.
*/
t_list		*ft_strarrtolst(int argc, char **argv)
{
	t_list		*list;

	if (argc < 0)
		argc = ft_arrlen((const void**)argv);
	if (argc == 0)
		return (NULL);
	list = NULL;
	while (argc > 0)
	{
		argc--;
		if (!ft_lstaddstr(&list, argv[argc]))
			return (NULL);
	}
	return (list);
}
