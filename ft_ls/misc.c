/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 19:39:37 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/15 20:18:43 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_ls.h"

void		*ft_memcpy(void *s1, const void *s2, int n)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char*)s1;
	tmp2 = (char*)s2;
	while (n--)
		*tmp1++ = *tmp2++;
	return (s1);
}

int			ft_nblen(long int nb)
{
	int		count;

	count = (nb <= 0 ? 1 : 0);
	while (nb)
	{
		nb /= 10;
		++count;
	}
	return (count);
}

int			ft_strcmp(char *name1, char *name2)
{
	while (*name1 == *name2 && *name1 != 0)
	{
		++name1;
		++name2;
	}
	if (*name1 < 0 && *name2 >= 0)
		return (1);
	if (*name1 >= 0 && *name2 < 0)
		return (-1);
	return (*name1 - *name2);
}

int			is_nothidden(const char *path)
{
	int		i;

	if (!ft_strcmp((char *)path, ".") || !ft_strcmp((char *)path, ".."))
		return (1);
	i = ft_strlen(path);
	while (--i >= 0)
	{
		if (path[i] == '/')
		{
			if (path[i + 1] == '.')
				return (0);
			return (1);
		}
	}
	return (1);
}
