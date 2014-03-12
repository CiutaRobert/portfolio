/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 19:17:49 by fflorens          #+#    #+#             */
/*   Updated: 2014/01/29 19:30:31 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<unistd.h>
#include		<limits.h>
#include		<corewar_asm.h>

int			g_dir[] = {4, 4, 0, 0, 0, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4};
int			g_ocp[] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1};

static void		write_ocp(char *line, int fd)
{
	int			i;
	char		ocp_byte;

	i = 0;
	ocp_byte = 0;
	while (line[i])
	{
		while (line[i] && line[i] != ' ' && line[i] != '\t')
			++i;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			++i;
		if (line[i] == '#' || line[i] == ';')
			i = skiptoend(line, i);
		else if (line[i] == 'r')
			ocp_byte = (ocp_byte << 2) + REG_CODE;
		else if (line[i] == '%')
			ocp_byte = (ocp_byte << 2) + DIR_CODE;
		else if (line[i])
			ocp_byte = (ocp_byte << 2) + IND_CODE;
	}
	ocp_byte = (ocp_byte <= 0x3 ? ocp_byte << 2 : ocp_byte);
	ocp_byte = (ocp_byte <= 0xF ? ocp_byte << 2 : ocp_byte);
	ocp_byte <<= 2;
	write(fd, &ocp_byte, 1);
}

static int		get_labeladdr(t_all *all, char *label, int cur_addr)
{
	t_labl		*tmp;

	tmp = all->labl;
	while (tmp)
	{
		if (!ft_strncmp(label, tmp->str, tmp->len))
		{
			if (tmp->addr >= cur_addr)
			{
				return (tmp->addr - cur_addr);
			}
			else
			{
				return (USHRT_MAX + 1 - (cur_addr - tmp->addr));
			}
		}
		tmp = tmp->next;
	}
	return (-1);
}

static int		write_dir(char *line, int fd, int cur_addr, t_all *all)
{
	int			oct;

	if (line[1] == ':')
		oct = get_labeladdr(all, line + 2, cur_addr);
	else
		oct = ft_atoi(line + 1);
	oct = to_big_endian(oct, all->cur_dir);
	write(fd, &oct, all->cur_dir);
	return (all->cur_dir);
}

static int		write_indreg(char *line, int fd, t_type type)
{
	int			oct;

	if (type == IND)
	{
		oct = ft_atoi(line);
		oct = to_big_endian(oct, 2);
		write(fd, &oct, 2);
		return (2);
	}
	else
	oct = ft_atoi(line);
	write(fd, &oct, 1);
	return (1);
}

void			write_line(t_all *all, char *line, int opcode, int fd)
{
	static int	cur_addr = 0;
	int			i;
	int			tmp_addr;

	tmp_addr = 1;
	all->cur_ocp = g_ocp[opcode - 1];
	all->cur_dir = g_dir[opcode - 1];
	write(fd, &opcode, 1);
	if (all->cur_ocp && (++tmp_addr))
		write_ocp(line, fd);
	i = 0;
	while (line[i])
	{
		i = skipnospacetabs(i, line);
		i = skipspacetabs(i, line);
		if (line[i] == 'r')
			tmp_addr += write_indreg(line + i + 1, fd, REG);
		else if (line[i] == '%')
			tmp_addr += write_dir(line + i, fd, cur_addr, all);
		else if (line[i] != '#' && line[i] != ';' && line[i])
			tmp_addr += write_indreg(line + i, fd, IND);
		else
			i = skiptoend(line, i);
	}
	cur_addr += tmp_addr;
}
