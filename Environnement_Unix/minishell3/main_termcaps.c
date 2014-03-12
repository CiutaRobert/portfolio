/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_termcaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 02:09:14 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/09 04:20:38 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>
#include	<term.h>
#include	"ft_sh.h"

static int	handle_buf(t_all *all, char *buf)
{
	int		i;
	t_func	ptr[5] = {{1, &go_start}, {5, &go_end}, {11, &cut_line},
					{16, &paste_line}, {127, &del_prev_char}};

	i = -1;
	while (++i < 5)
	{
		if (buf[0] == ptr[i].code)
			ptr[i].func(all);
	}
	if (buf[0] == 10)
		return (SEND_LINE);
	else if (buf[0] == 4 && !all->line[0])
		return (send_exit(all));
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 51 && buf[3] == 126)
		del_char(all);
	else if (buf[0] == 27)
		handle_cursor(all, buf);
	else
	{
		i = -1;
		while (buf[++i] >= ' ' && buf[i] <= '~' && all->cursor_x < BUFF_SIZE)
			insert_char(all, buf[i]);
	}
	return (OK);
}

static int	read_all(t_all *all)
{
	char	buf[2048];
	int		ret;

	all->cursor_x = 0;
	ret = 1;
	while (ret > 0)
	{
		if ((ret = read(0, buf, 2048)) == -1)
			return (puterror("read"));
		buf[ret] = -42;
		if (handle_buf(all, buf) != OK)
			ret = 0;
	}
	return (OK);
}

int			main_termcaps(t_all *all)
{
	if (init_termcaps(all) == NOT_OK)
		return (NOT_OK);
	all->cursor_y = all->max_y;
	read_all(all);
	ft_putchar('\n');
	if (all->line[0])
		++all->max_y;
	if (stop_termcaps(all) == NOT_OK)
		return (NOT_OK);
	return (OK);
}
