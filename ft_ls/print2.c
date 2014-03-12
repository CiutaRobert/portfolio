/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 01:43:19 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/15 20:23:23 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<time.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"ft_ls.h"

void		print_device(t_file *cur, t_file *list)
{
	int		nb_blank;
	int		i;

	nb_blank = (S_ISCHR(cur->info->st_mode) || S_ISBLK(cur->info->st_mode)
				? ft_nblen(major(cur->info->st_rdev)) : 0);
	nb_blank = list->maxlen[DEVICE] - nb_blank;
	i = -1;
	while (++i < nb_blank)
		ft_putchar(' ');
	if (S_ISCHR(cur->info->st_mode) || S_ISBLK(cur->info->st_mode))
	{
		ft_putchar(' ');
		ft_putnbr(major(cur->info->st_rdev));
		ft_putstr(", ");
	}
	else if (list->maxlen[DEVICE] > 0)
		ft_putstr("   ");
}

void		print_size(t_file *cur, t_file *list)
{
	int		nb_blank;
	int		i;

	nb_blank = (S_ISCHR(cur->info->st_mode) || S_ISBLK(cur->info->st_mode)
				? ft_nblen(minor(cur->info->st_rdev))
				: ft_nblen(cur->info->st_size));
	nb_blank = list->maxlen[SIZE] - nb_blank;
	i = -1;
	while (++i < nb_blank)
		ft_putchar(' ');
	if (S_ISCHR(cur->info->st_mode) || S_ISBLK(cur->info->st_mode))
		ft_putnbr(minor(cur->info->st_rdev));
	else
		ft_putnbr(cur->info->st_size);
	ft_putchar(' ');
}

void		print_time(time_t *file_time)
{
	int		i;
	char	*str;
	time_t	current;

	str = ctime(file_time);
	current = time(NULL);
	if (current - *file_time < 0 || current - *file_time >= 15552000)
	{
		i = ft_strlen(str) - 1;
		str[i] = 0;
		while (str[i] != ' ')
			--i;
		write(1, str + 4, 7);
		ft_putstr(str + i);
	}
	else
		write(1, str + 4, ft_strlen(str) - 13);
	ft_putchar(' ');
}

void		print_slink(const char *path, const char *name)
{
	char	buf[1025];
	int		ret;
	char	*full_path;

	if ((full_path = ft_strjoin(path, name)) != NULL)
	{
		if ((ret = readlink(full_path, buf, 1024)) != -1)
		{
			buf[ret] = 0;
			ft_putstr(" -> ");
			ft_putstr(buf);
		}
		free(full_path);
	}
}
