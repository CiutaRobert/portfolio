/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:47:16 by jzak              #+#    #+#             */
/*   Updated: 2014/01/31 22:00:56 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"
#include "op.h"
#include "VM.h"

/*
** Load champion in memory
*/
static t_champion	*load_champion(const char *str, int id, char *buf)
{
	t_champion		*champ;
	int				fd;
	unsigned int	size;

	champ = secure_calloc(sizeof(*champ));
	if ((fd = open(str, O_RDONLY)) == -1)
		error(help, "failed to open file : %s\n", str);
	if (read(fd, &champ->header, sizeof(t_header)) != sizeof(t_header))
		error(help, "invalid header\n");
	swap_u32(&champ->header.prog_size);
	swap_u32(&champ->header.magic);
	size = champ->header.prog_size;
	if (champ->header.magic != COREWAR_EXEC_MAGIC || size  > CHAMP_MAX_SIZE)
		error(help, "invalid header\n");
	champ->process = secure_calloc(sizeof(t_process));
	champ->process->pc = buf;
	if (read(fd, buf, size + 1) != (int)size)
		error(help, "invalid bytecode size\n");
	champ->id = id;
	champ->process->reg[0] = id;
	close(fd);
	return (champ);
}

static int			get_pgid(t_battle *battle, int id)
{
	t_champion	*champ;
	int			i;

	i = 0;
	while ((champ = battle->champion[i]) != NULL)
	{
		if (champ->id == id)
			return (get_pgid(battle, id + 1));
		++i;
	}
	return (id);
}

void				c_opt(char **av, int ac, void *data)
{
	(void)av;
	(void)ac;
	(void)data;
	ihm.mode = 1;
}

void				dump_opt(char **av, int ac, void *data)
{
	t_battle	*battle;

	(void)ac;
	battle = (t_battle*)data;
	if (!ft_getnbr(&av[1], &battle->dump))
		error(help, "invalid argument of option dump: %s\n", av[0]);
	if (battle->dump < 1)
		error(help, "dump does not take a negative value: %d\n", battle->dump);
}

void				n_opt(char **av, int ac, void *data)
{
	int			id;
	t_battle	*b;
	int			pos;
	t_champion	*champ;

	b = (t_battle*)data;
	--ac;
	pos = b->nbr_champion * (MEM_SIZE / MAX_PLAYERS);
	b->nbr_champion++;
	if (ac == 1)
		id = b->nbr_champion;
	else if (!ft_getnbr(&av[1], &id))
		error(help, "invalid argument of option n:\n");
	id = get_pgid(b, id);
	if (b->nbr_champion > MAX_PLAYERS)
		error(help, "too many champions\n");
	champ = load_champion(av[ac], id, &b->memory[pos]);
	b->champion[b->nbr_champion - 1] = champ;
	ft_memset(&b->belongs[pos], id, champ->header.prog_size);
}
