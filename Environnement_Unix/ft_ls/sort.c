/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:14:11 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/13 02:00:49 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"ft_ls.h"

int			classic_order(t_file *elem1, t_file *elem2)
{
	if (!elem1->info || !elem2->info)
	{
		if (elem1->info && !elem2->info)
			return (1);
		if (!(!elem1->info && ! elem2->info))
			return (-1);
	}
	return (ft_strcmp(elem1->name, elem2->name));
}

int			time_order(t_file *elem1, t_file *elem2)
{
	int		size1;
	int		size2;

	if (!elem1->info || !elem2->info)
	{
		if (elem1->info && !elem2->info)
			return (1);
		return (-1);
	}
	size1 = elem1->info->st_mtime;
	size2 = elem2->info->st_mtime;
	if (size2 - size1 == 0)
		return (classic_order(elem1, elem2));
	return (size2 - size1);
}

void		bubble_sort(t_file **list,
						int (*cmp)(t_file *elem1, t_file *elem2))
{
	t_file	*tmp;
	void	*swap;
	int		is_sort;

	tmp = *list;
	is_sort = 0;
	while (!is_sort && (is_sort = 1))
	{
		*list = tmp;
		while (*list && (*list)->next)
		{
			if (cmp(*list, (*list)->next) > 0)
			{
				swap = (char *)((*list)->name);
				(*list)->name = (*list)->next->name;
				(*list)->next->name = (char *)swap;
				swap = (struct stat *)((*list)->info);
				(*list)->info = (*list)->next->info;
				(*list)->next->info = (struct stat *)swap;
				is_sort = 0;
			}
			*list = (*list)->next;
		}
	}
	*list = tmp;
}

void		call_ftls_again(t_file *list, const char *path, char *opt)
{
	t_file	*tmp;
	char	*full_path;

	tmp = (opt[REVERSE_SORT] == ON ? ft_lstlast(list) : list);
	while (tmp)
	{
		if (ft_strcmp(tmp->name, ".") && ft_strcmp(tmp->name, "..")
			&& tmp->info && S_ISDIR(tmp->info->st_mode))
		{
			if ((full_path = ft_strjoin(path, tmp->name)) != NULL)
			{
				if (is_nothidden(full_path) || opt[PRINT_HIDDEN] == ON)
				{
					ft_putchar('\n');
					ft_putstr(full_path);
					ft_putstr(":\n");
				}
				read_dir(full_path, opt);
				free(full_path);
			}
		}
		tmp = (opt[REVERSE_SORT] == ON ? tmp->prev : tmp->next);
	}
}

void		aff_sorted_list(t_file *list, const char *path,
							int total, char *opt)
{
	int		len;

	len = ft_lstlen(list, opt);
	if (opt[TIME_SORT] == ON)
		bubble_sort(&list, &time_order);
	else
		bubble_sort(&list, &classic_order);
	if (len && (is_nothidden(path) || opt[PRINT_HIDDEN] == ON))
	{
		if (opt[LIST_DETAIL] == ON && len)
			option_l(list, total, opt, (char *)path);
		else
			no_option(list, opt);
	}
	if (opt[RECURSIVE] == ON)
		call_ftls_again(list, path, opt);
}
