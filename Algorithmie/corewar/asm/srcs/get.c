/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 19:17:24 by fflorens          #+#    #+#             */
/*   Updated: 2014/01/29 19:25:12 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<fcntl.h>
#include	<unistd.h>
#include	<limits.h>
#include	<stdlib.h>
#include	<corewar_asm.h>

static char		get_cmd(char *str, int *cur_dir, unsigned int *prog_size)
{
	int			opcode;
	int			dir[] = {4, 4, 0, 0, 0, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4};
	int			ocp[] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1};
	char		*cmdtb[] = {"live", "ld", "st", "add", "sub", "and", "or",
							"xor", "zjmp", "ldi", "sti", "fork", "lld",
							"lldi", "lfork", "aff"};

	opcode = -1;
	while (++opcode < 16)
	{
		if (!ft_strcmp(str, cmdtb[opcode]))
		{
			if (cur_dir)
				*cur_dir = dir[opcode];
			if (prog_size)
				*prog_size += ocp[opcode] - 1;
			return (opcode + 1);
		}
	}
	return (-1);
}

static void		get_string_value(char **line, char *str_value)
{
	int			i;
	int			j;

	i = 0;
	while ((*line)[i] && (*line)[i] != '"')
		++i;
	++i;
	j = -1;
	while ((*line)[i + ++j] && (*line)[i + j] != '"')
		str_value[j] = (*line)[i + j];
	free(*line);
	*line = "";
}

static int		processitem(char *str, t_all *all, int *cur_dir, int i)
{
	i = skipspacetabs(i, str);
	if (str[i] == 'r')
		all->header.prog_size += 1;
	else if (str[i] == '%')
		all->header.prog_size += *cur_dir;
	else if (str[i] == '#' || str[i] == ';')
		i = skiptoend(str, i);
	else if (str[i])
	{
		all->header.prog_size += 2;
		get_cmd(str + i, cur_dir, &all->header.prog_size);
	}
	return (skipnospacetabs(i, str));
}

void			get_labels_and_size(t_all *all)
{
	int			i;
	int			cur_dir;
	t_list		*tmp;

	cur_dir = 4;
	tmp = all->list;
	all->header.prog_size = 0;
	while (tmp)
	{
		if (!ft_strcmp(tmp->str, NAME_CMD_STRING))
			get_string_value(&tmp->str, all->header.prog_name);
		if (!ft_strcmp(tmp->str, COMMENT_CMD_STRING))
			get_string_value(&tmp->str, all->header.comment);
		i = skipnospacetabs(0, tmp->str);
		if (i - 2 >= 0 && tmp->str[i - 1] == ':')
			lbl_pushback(&all->labl, tmp->str, i - 1, all->header.prog_size);
		else
			i = 0;
		while (tmp->str[i])
			i = processitem(tmp->str, all, &cur_dir, i);
		tmp = tmp->next;
	}
	all->header.prog_size = to_big_endian(all->header.prog_size, 4);
}

void			parse_code(t_all *all, int fd)
{
	char		opcode;
	t_list		*tmp;
	int			i;

	tmp = all->list;
	while (tmp)
	{
		i = 0;
		while (tmp->str[i])
		{
			i = skipspacetabs(i, tmp->str);
			if (tmp->str[i] != 'r' && tmp->str[i] != '%' && tmp->str[i])
			{
				if ((opcode = get_cmd(tmp->str + i, NULL, NULL)) != -1)
				{
					write_line(all, tmp->str + i, opcode, fd);
					i = skiptoend(tmp->str, i);
				}
			}
			else if (tmp->str[i] == '#' || tmp->str[i] == ';')
					i = skiptoend(tmp->str, i);
			i = skipnospacetabs(i, tmp->str);
		}
		tmp = tmp->next;
	}
}
