/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dirname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 20:19:40 by nmokrane          #+#    #+#             */
/*   Updated: 2013/12/11 13:03:51 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the path of the parent directory.
** If there are no slashes in path, a dot ('.') is returned,
** indicating the current directory. Otherwise, the returned string
** is path with any trailing /component removed. (UNIX / only)
** If string allocation fails, the function returns NULL.
** If the dirname is /, it is returned as it is. Therefore, is the dirname
** is composed of multiple slashs, the last one will be removed
**
** WARNING: Unlike ft_basename, a new string is created when calling dirname.
*/
char	*ft_dirname(char *path)
{
	char	*dir;
	char	*end;

	dir = ft_strdup(path);
	if (dir == NULL)
		return (NULL);
	end = ft_strrchr(dir, '/');
	if (end == NULL)
		return (".");
	if (end == dir)
		end++;
	*end = '\0';
	return (dir);
}
