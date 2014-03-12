/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:22:16 by jzak              #+#    #+#             */
/*   Updated: 2014/02/02 22:51:52 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <stdlib.h>
# include <fcntl.h>
# include <curses.h>
# include <panel.h>
# include "op.h"

# define COL_INFO 60
# define LINE_INFO 20

# define PRINT(_y, _x, _f, ...) mvwprintw(ihm.info, _y, _x, _f, ##__VA_ARGS__);

/*
** Global variable
*/
extern struct s_ihm		ihm;

typedef enum			s_battle_status
{
	HAS_WINNER = 1,
	CORE_DUMP = 2
}						t_battle_status;

typedef struct			s_process
{
	t_uint				reg[REG_NUMBER];
	char				*pc;
	t_bool				carry;
	t_uint				nbr_live;
	t_ulong				consumed;
	struct s_process	*next;
	struct s_process	*prev;
}						t_process;

typedef struct			s_champion
{
	t_header			header;
	t_process			*process;
	int					id;
	int					is_dead;
	t_uint				consumed;
}						t_champion;

typedef struct			s_battle
{
	char				memory[MEM_SIZE];
	char				belongs[MEM_SIZE];
	t_champion			*champion[MAX_PLAYERS + 1];
	t_champion			*curr_champion;
	t_process			*curr_process;
	t_uint				nbr_champion;
	t_uint				cycle_to_die;
	int					dump;
	t_ulong				cycle;
}						t_battle;

typedef enum			s_ihm_status
{
	QUIT = 0,
	PAUSE = 1,
	RUN = 2,
	STEP = 3
}						t_ihm_status;

typedef struct			s_ihm
{
	int					nbr_collumn;
	int					nbr_line;
	WINDOW				*main;
	WINDOW				*info;
	WINDOW				*print;
	PANEL				*panels[3];
	int					status;
	t_battle			*battle;
	t_bool				mode;
}						t_ihm;

typedef t_bool (*t_event_fn)(t_battle *battle, t_op *op, t_u16 pc);

typedef struct			s_event
{
	char				*name;
	t_event_fn			fn;
}						t_event;

t_bool			ft_live(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_ld(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_st(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_add(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_sub(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_and(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_or(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_xor(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_zjmp(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_ldi(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_sti(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_fork(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_lld(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_lldi(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_lfork(t_battle *battle, t_op *op, t_u16 pc);
t_bool			ft_aff(t_battle *battle, t_op *op, t_u16 pc);

/*
** main.c
*/
void			help(void);

/*
** load.c
*/
void			c_opt(char **av, int ac, void *data);
void			dump_opt(char **av, int ac, void *data);
void			n_opt(char **av, int ac, void *data);

/*
** check.c
*/
t_bool			is_dead(t_battle *battle);

/*
** instruction.c
*/
t_uint			get_op_consumption(t_process *process);
t_uint			get_consumption(t_process *process);
t_uint			execute_op(t_battle *battle);

/*
** battle.c
*/
int				run_battle(t_battle *battle);
void			run_process(t_battle *battle);
void			free_battle(t_battle *battle);

/*
** battle_sync.c
*/
t_uint			min_consumption(t_battle *battle);
t_uint			max_consumption(t_battle *battle);
void			sort_by_consumtion(t_battle *b);
void			sync_consumption(t_battle *battle, t_uint max_consumption);
void			reset_consumption(t_battle *battle, t_uint min_consumption);

/*
** process_sync.c
*/
t_uint			proc_max_consumption(t_process *process);
t_uint			proc_min_consumption(t_process *process);
void			proc_sort_by_consumtion(t_process *p);
void			proc_sync_consumption(t_battle *b, t_process *p, t_uint max);
void			proc_reset_consumption(t_process *process, t_uint min_consume);

/*
** ihm.c
*/
void			init_ihm(void);
void			print_ihm(const char *format, ...);
void			draw_ihm(t_battle *battle);
void			destroy_ihm(void);

/*
** ihm_evt.c
*/
void			pause_evt(void *data);
void			info_evt(void *data);
void			print_evt(void *data);
void			step_evt(void *data);
void			quit_evt(void *data);

/*
** ihm_draw.c
*/
void			draw_main(void);
void			draw_info(void);
void			draw_print(void);

#endif /* !VM_H */
