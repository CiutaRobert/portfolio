/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 15:30:34 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/15 20:06:57 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<pwd.h>
#include	<grp.h>
#include	<sys/types.h>
#include	<stdlib.h>
#include	"ft_ls.h"

static void	ft_lstmaxlen(t_file **list, t_file *new)
{
	int		*lst;
	int		tmp;

	lst = (*list)->maxlen;
	if (lst[HARD_LINK] < (tmp = ft_nblen(new->info->st_nlink)))
		lst[HARD_LINK] = tmp;
	tmp = (getpwuid(new->info->st_uid)
			? ft_strlen(getpwuid(new->info->st_uid)->pw_name)
			: ft_nblen(new->info->st_uid));
	lst[UID] = (lst[UID] < tmp ? tmp : lst[UID]);
	tmp = (getgrgid(new->info->st_gid)
			? ft_strlen(getgrgid(new->info->st_gid)->gr_name)
			: ft_nblen(new->info->st_gid));
	lst[GID] = (lst[GID] < tmp ? tmp : lst[GID]);
	if ((S_ISCHR(new->info->st_mode) || S_ISBLK(new->info->st_mode))
		&& (tmp = ft_nblen(major(new->info->st_rdev))) > lst[DEVICE])
		lst[DEVICE] = tmp;
	tmp = (S_ISCHR(new->info->st_mode) || S_ISBLK(new->info->st_mode)
			? ft_nblen(minor(new->info->st_rdev))
			: ft_nblen(new->info->st_size));
	lst[SIZE] = (lst[SIZE] < tmp ? tmp : lst[SIZE]);
}

t_file		*ft_lstnew(char *name, struct stat *info)
{
	t_file	*elem;
	int		len;

	if ((elem = (t_file *)malloc(sizeof(*elem))) == NULL)
		return (NULL);
	elem->info = NULL;
	elem->name = NULL;
	if (info)
	{
		if ((elem->info = malloc(sizeof(*info))) == NULL)
			return (NULL);
		elem->info = ft_memcpy(elem->info, info, sizeof(*info));
	}
	if (name)
	{
		len = ft_strlen(name);
		if ((elem->name = malloc(len + 1)) == NULL)
			return (NULL);
		elem->name = ft_memcpy(elem->name, name, len);
		(elem->name)[len] = 0;
	}
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void		ft_lstpushback(t_file **list, t_file *new, char *opt)
{
	int		i;
	t_file	*tmp;

	if (!list || !new)
		return ;
	if (*list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		if (new->info && (new->name[0] != '.' || opt[PRINT_HIDDEN] == ON))
			ft_lstmaxlen(list, new);
		new->prev = tmp;
	}
	else
	{
		*list = new;
		i = -1;
		while (++i < INFODONE)
			(*list)->maxlen[i] = 0;
	}
}

t_file		*ft_lstlast(t_file *list)
{
	t_file	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int			ft_lstlen(t_file *list, char *opt)
{
	int		len;
	t_file	*tmp;

	len = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->name[0] != '.' || opt[PRINT_HIDDEN] == ON)
			++len;
		tmp = tmp->next;
	}
	return (len);
}
