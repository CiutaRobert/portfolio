/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 20:15:08 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/11 13:04:19 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Given a string containing the path to a file or directory,
** this function will return the trailing name component. (UNIX / only)
**
** WARNING: Unlike ft_dirname, there is no string duplication, which means
** that the returned pointer is relative to the given path string.
*/
char	*ft_basename(char *path)
{
	char	*name;

	name = ft_strrchr(path, '/');
	if (name == NULL)
		return (path);
	return (name + 1);
}
