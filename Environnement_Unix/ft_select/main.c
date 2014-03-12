/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:03:23 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/12 22:03:24 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<unistd.h>
#include		<stdlib.h>
#include		<term.h>
#include		<signal.h>
#include		"ft_select.h"

static t_list	*handle_buf(t_all *all, char buf[10],
							t_list **choice, t_dbl *pos)
{
	int			save;

	if ((buf[0] == 27 && buf[1] == 91
		&& buf[2] == 51 && buf[3] == 126) || buf[0] == 127)
	{
		save = pos->y;
		if (lst_is_inside(*choice, pos->y))
			lst_del(choice, save);
		ft_cursor_down(all, pos);
		lst_del(&all->full, save);
		--all->last_elem;
	}
	else if (buf[0] == 27 && buf[1] == 91)
		handle_cursor(all, pos, buf[2]);
	else if (buf[0] == ' ')
		handle_select(all, choice, pos);
	else if (buf[0] == '\n' || buf[0] == 27)
		return (NULL);
	return (OK);
}

static t_list	*read_select(t_all *all)
{
	t_list		*choice;
	char		buf[10];
	int			ret;
	t_dbl		pos;

	choice = NULL;
	pos.x = 0;
	pos.y = 0;
	ret = 1;
	while (ret > 0 && all->last_elem >= 0)
	{
		lst_aff(all);
		if ((ret = read(0, buf, 10)) == -1)
			return (puterror("read"));
		buf[ret] = 0;
		if (handle_buf(all, buf, &choice, &pos) != OK)
			ret = 0;
	}
	if (buf[0] == 27)
		return (NULL);
	return (choice);
}

static t_list	*ft_select(int ac, char **av)
{
	char		*term_name;
	t_list		*choice;
	int			i;

	if ((term_name = getenv("TERM")) == NULL)
		return (puterror("getenv"));
	if (tgetent(NULL, term_name) <= 0)
		return (puterror("tgetent"));
	if (tcgetattr(0, &g_all.term) == -1)
		return (puterror("tcgetattr"));
	if (init_termcaps(&g_all) == NULL || init_all(&g_all, ac, av) == NULL)
		return (NULL);
	get_sigwinch(42);
	i = -1;
	while (++i < 64)
		signal(i, &get_other_sig);
	signal(SIGWINCH, &get_sigwinch);
	signal(SIGTSTP, &get_sigtstp);
	signal(SIGCONT, &get_sigcont);
	choice = read_select(&g_all);
	stop_termcaps(&g_all);
	close(g_all.fd);
	lst_free(&g_all.full);
	return (choice);
}

int				main(int ac, char **av)
{
	t_list		*choice;
	t_list		*tmp;
	int			flag;

	if (ac < 2)
		return (1);
	flag = 0;
	if ((choice = ft_select(ac, av)) == NULL)
		return (0);
	tmp = choice->prev;
	while (tmp != choice || !flag)
	{
		if (!flag++)
			tmp = choice;
		if (tmp != choice)
			write(1, " ", 1);
		ft_putstr_fd(1, tmp->str);
		tmp = tmp->next;
	}
	lst_free(&choice);
	return (0);
}
