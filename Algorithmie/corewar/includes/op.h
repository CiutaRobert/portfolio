/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2014/02/02 18:31:58 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include <stdlib.h>

/*
** All defined sizes represent octet numbers.
** We assume that an int is 32 bits long. Is that true on your own platform ?
*/
# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4 * 1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10


# define T_REG					1
# define T_DIR					2
# define T_IND					4

/*
** Global corewar core conventions
*/
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

/*
** Boolean abstraction layer
*/
typedef int				t_bool;

# ifndef true
#  define true 1
# endif
# ifndef false
#  define false 0
# endif

/*
** Basic type
*/
typedef unsigned char	t_u8;
typedef unsigned short	t_u16;
typedef unsigned int	t_u32;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;
typedef void (*t_helpfn) (void);

/*
** Binary flags for ASM instruction argument types
*/
typedef char			t_arg_type;

/*
** This structure represents champion bytecode headers
*/
typedef struct			s_header
{
	t_uint				magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	t_uint				prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						t_header;

/*
** The structure represents a single operation to be executed by
** the virtual machine
*/
typedef struct			s_op
{
	char				*label;
	int					argc;
	int					argv[4];
	t_uint				opcode;
	t_uint				consumption;
	char				*description;
	t_uint				has_byte_coding;
	int					has_idx;
}						t_op;

/*
** Global variable
*/
extern t_op				 op_tab[17];

/*
** argv argc parser
*/
typedef void (*t_opt_fn)(char **av, int ac, void *userdata);

typedef struct			s_opt_elem
{
	const char			*name;
	t_uint				nbr_val;
	t_opt_fn			fn;
	struct s_opt_elem	*next;
}						t_opt_elem;

typedef struct			s_opt
{
	t_opt_elem			*elem;
	t_opt_elem			*def;
	t_helpfn			help;
	char				**av;
	int					ac;
	int					i;
	char				**value;
	t_uint				max_opt;
}						t_opt;

t_opt		*init_opt(t_opt_fn def, int ac, char **av, t_helpfn help);
void		add_opt(t_opt *opt, const char *name, t_uint nbr_val, t_opt_fn fn);
void		parse_opt(t_opt *opt, void *data);
void		destroy_opt(t_opt **opt);

/*
** Core functions
*/
void		warning(const char *fmt, ...);
void		error(void (*help) (void), const char *fmt, ...);
void		*secure_malloc(size_t size);
void		*secure_calloc(size_t size);
t_u16		swap_u16(t_u16 *v);
t_u32		swap_u32(t_u32 *v);
t_uint		to_big_endian(unsigned int nb, int size);

#endif /* !OP_H */
