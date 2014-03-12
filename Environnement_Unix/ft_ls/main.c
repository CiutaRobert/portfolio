/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 19:38:51 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/15 20:17:49 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			<stdlib.h>
#include			<dirent.h>
#include			"ft_ls.h"

int					get_info(t_file **list, char *path,
							 char *filename, char *opt)
{
    struct stat		info;
	char			*full_path;
	int				total;

	total = 0;
	full_path = ft_strjoin(path, filename);
	if (full_path && lstat(full_path, &info) != -1)
	{
		if (filename[0] != '.' || opt[PRINT_HIDDEN] == ON)
			total += info.st_blocks;
		ft_lstpushback(list, ft_lstnew(filename, &info), opt);
	}
	else
		ft_lstpushback(list, ft_lstnew(filename, NULL), opt);
	if (full_path)
		free(full_path);
	return (total);
}

void				read_dir(char *path, char *opt)
{
	DIR				*dir;
	struct dirent	*file;
	t_file			*list;
	int				total;

	total = 0;
	list = NULL;
	if ((dir = opendir(path)) == NULL)
		return (ft_perror(path));
	while ((file = readdir(dir)) != NULL)
		total += get_info(&list, path, file->d_name, opt);
	if (closedir(dir) == -1)
		return (ft_perror(NULL));
	aff_sorted_list(list, path, total, opt);
}

void				aff_path(t_file *list, char *opt, int max_path)
{
	t_file			*tmp;

	tmp = (opt[REVERSE_SORT] ? ft_lstlast(list) : list);
	while (tmp)
	{
		if (!tmp->info)
			ft_perror(tmp->name);
		else
		{
			if (max_path > 1)
			{
				ft_putstr(tmp->name);
				ft_putstr(":\n");
			}
			read_dir(tmp->name, opt);
			if ((opt[REVERSE_SORT] && tmp->prev)
				|| (!opt[REVERSE_SORT] && tmp->next))
				ft_putchar('\n');
		}
		tmp = (opt[REVERSE_SORT] ? tmp->prev : tmp->next);
	}
}

void				ft_ls(int nb_path, int total_path, char **paths, char *opt)
{
	int				i;
	t_file			*list;
	struct stat		info;

	if (nb_path == -1 || total_path == nb_path)
		read_dir(".", opt);
	else
	{
		list = NULL;
		i = nb_path - 1;
		while (++i < total_path)
		{
			if (lstat(paths[i], &info) != -1)
				ft_lstpushback(&list, ft_lstnew(paths[i], &info), opt);
			else
				ft_lstpushback(&list, ft_lstnew(paths[i], NULL), opt);
		}
		bubble_sort(&list, &classic_order);
		if (opt[TIME_SORT] == ON)
			bubble_sort(&list, &time_order);
		aff_path(list, opt, total_path - nb_path);
	}
}

int					main(int ac, char **av)
{
	char			opt[OPTDONE];
	int				nb_path;

	set_all_off(opt);
	if ((nb_path = parse_arg(ac, av, opt)) == -42)
		return (1);
	ft_ls(nb_path, ac, av, opt);
	return (0);
}
