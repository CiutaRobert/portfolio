/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 01:41:47 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/15 20:22:56 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<grp.h>
#include		<pwd.h>
#include		"ft_ls.h"

static void		print_mode_first(int file_mode)
{
	if (S_ISDIR(file_mode))
		ft_putchar('d');
	else if (S_ISLNK(file_mode))
		ft_putchar('l');
	else if (S_ISFIFO(file_mode))
		ft_putchar('p');
	else if (S_ISSOCK(file_mode))
		ft_putchar('s');
	else if (S_ISCHR(file_mode))
		ft_putchar('c');
	else if (S_ISBLK(file_mode))
		ft_putchar('b');
	else
		ft_putchar('-');
}

void		print_mode(int file_mode)
{
	char	value[3] = "xwr";
	char	sp_value[6] = "tssTSS";
	int		i;

	print_mode_first(file_mode);
	i = 9;
	while (--i >= 0)
	{
		if (file_mode & (1 << i))
		{
			if ((!i && (file_mode & 01000)) || (i == 3 && (file_mode & 02000))
				|| (i == 6 && (file_mode & 04000)))
				ft_putchar(sp_value[i / 3]);
			else
				ft_putchar(value[i % 3]);
		}
		else if ((!i && (file_mode & 01000)) || (i == 3 && (file_mode & 02000))
				|| (i == 6 && (file_mode & 04000)))
			ft_putchar(sp_value[(i / 3) + 3]);
		else
			ft_putchar('-');
	}
	ft_putstr("  ");
}

void		print_hlink(int nb_link, t_file *list)
{
	int		nb_blank;
	int		i;

	nb_blank = list->maxlen[HARD_LINK] - ft_nblen(nb_link);
	i = -1;
	while (++i < nb_blank)
		ft_putchar(' ');
	ft_putnbr(nb_link);
	ft_putchar(' ');
}

void		print_uid(int uid, t_file *list)
{
	int		nb_blank;
	int		i;

	nb_blank = (getpwuid(uid)
				? ft_strlen(getpwuid(uid)->pw_name) : ft_nblen(uid));
	nb_blank = list->maxlen[UID] - nb_blank;
	if (getpwuid(uid))
		ft_putstr(getpwuid(uid)->pw_name);
	else
		ft_putnbr(uid);
	i = -1;
	while (++i < nb_blank)
		ft_putchar(' ');
	ft_putstr("  ");
}

void		print_gid(int gid, t_file *list)
{
	int		nb_blank;
	int		i;

	nb_blank = (getgrgid(gid)
				? ft_strlen(getgrgid(gid)->gr_name) : ft_nblen(gid));
	nb_blank = list->maxlen[GID] - nb_blank;
	if (getgrgid(gid))
		ft_putstr(getgrgid(gid)->gr_name);
	else
		ft_putnbr(gid);
	i = -1;
	while (++i < nb_blank)
		ft_putchar(' ');
	ft_putstr("  ");
}
