/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:17:36 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/13 01:44:05 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_ls.h"

void		option_l(t_file *list, int total, char *opt, char *path)
{
	t_file	*tmp;

	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
	tmp = (opt[REVERSE_SORT] ? ft_lstlast(list) : list);
	while (tmp)
	{
		if (tmp->name[0] != '.' || opt[PRINT_HIDDEN] == ON)
		{
			print_mode(tmp->info->st_mode);
			print_hlink(tmp->info->st_nlink, list);
			print_uid(tmp->info->st_uid, list);
			print_gid(tmp->info->st_gid, list);
			print_device(tmp, list);
			print_size(tmp, list);
			print_time(&(tmp->info->st_mtime));
			ft_putstr(tmp->name);
			if (S_ISLNK(tmp->info->st_mode))
				print_slink(path, tmp->name);
			ft_putchar('\n');
		}
		tmp = (opt[REVERSE_SORT] ? tmp->prev : tmp->next);
	}
}

void		no_option(t_file *list, char *opt)
{
	t_file	*tmp;

	tmp = (opt[REVERSE_SORT] ? ft_lstlast(list) : list);
	while (tmp)
	{
		if (tmp->name[0] != '.' || opt[PRINT_HIDDEN] == ON)
		{
			ft_putstr(tmp->name);
			if ((opt[REVERSE_SORT] && tmp->prev)
				|| (!opt[REVERSE_SORT] && tmp->next))
				ft_putchar('\n');
		}
		tmp = (opt[REVERSE_SORT] ? tmp->prev : tmp->next);
	}
	ft_putchar('\n');
}
