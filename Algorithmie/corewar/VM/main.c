/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 16:35:01 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 22:49:41 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf.h"
#include "op.h"
#include "VM.h"

void			help(void)
{
	ft_dprintf(STDERR_FILENO, "usage: ./corewar ");
	ft_dprintf(STDERR_FILENO, "[-c active ncurses interface] ");
	ft_dprintf(STDERR_FILENO, "");
	ft_dprintf(STDERR_FILENO, "[-dump nbr_cycles] ");
	ft_dprintf(STDERR_FILENO, "[[-n number] champion1.cor] ");
	ft_dprintf(STDERR_FILENO, "...\n");
}

static void		declare_winner(t_battle *battle)
{
	t_champion		*c;
	int				i;

	i = 0;
	while ((c = battle->champion[i]) != NULL)
	{
		if ((t_uint)c->is_dead == 1)
		{
			print_ihm("le joueur %d(%s) a gagne\n", c->id, c->header.prog_name);
		}
		else
			print_ihm("%s est %deme\n", c->header.prog_name, c->id, c->is_dead);
		++i;
	}
}

static void		core_dump(char *memory)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%02X", (unsigned int)(unsigned char)(memory[i]));
		i++;
		if (i % 32 == 0)
			ft_printf("\n");
		else
			ft_printf(" ");
	}
}

static void		parse_argument(t_helpfn h, int ac, char **av, t_battle *b)
{
	t_opt		*opt;

	opt = init_opt(n_opt, ac, av, h);
	add_opt(opt, "c", 0, c_opt);
	add_opt(opt, "dump", 1, dump_opt);
	add_opt(opt, "n", 2, n_opt);
	parse_opt(opt, b);
	destroy_opt(&opt);
	if (b->nbr_champion == 0)
		error(help, "not enough champion\n");
}

int				main(int ac, char **av)
{
	t_battle	*battle;
	int			status;

	if (ac == 1)
	{
		help();
		return (0);
	}
	battle = secure_calloc(sizeof(t_battle));
	battle->cycle_to_die = CYCLE_TO_DIE;
	parse_argument(help, ac, av, battle);
	init_ihm();
	status = run_battle(battle);
	destroy_ihm();
	if (status == CORE_DUMP)
		core_dump(battle->memory);
	else if (status == HAS_WINNER)
		declare_winner(battle);
	free_battle(battle);
	return (0);
}
