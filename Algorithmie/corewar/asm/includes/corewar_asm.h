/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_asm.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 20:36:24 by fflorens          #+#    #+#             */
/*   Updated: 2014/01/29 22:36:36 by fflorens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				COREWAR_ASM_H
# define			COREWAR_ASM_H
# define			CORRECTOCT(A) (((A) + 1) + (((A) + 1) % 4))
# define			BUFF_SIZE 1024
# include			<op.h>
typedef struct		s_gnl
{
	char			*buffer;
	int				fd;
	int				i;
}					t_gnl;
typedef struct		s_lstd
{
	void			*content;
	struct s_lstd	*next;
	struct s_lstd	*prev;
}					t_lstd;
typedef enum		e_order
{
	LIST_BACK,
	LIST_FRONT
}					t_order;
typedef enum		e_type
{
	REG,
	IND
}					t_type;
typedef struct		s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;
typedef struct		s_labl
{
	char			*str;
	int				len;
	int				addr;
	struct s_labl	*next;
}					t_labl;
typedef struct		s_all
{
	t_list			*list;
	t_labl			*labl;
	t_header		header;
	int				cur_ocp;
	int				cur_dir;
}					t_all;

/*
**	list.c
*/
void				lst_pushback(t_list **list, char *str);
void				lbl_pushback(t_labl **list, char *str, int len, int pos);

/*
**	corelib.c
*/
int					skipspacetabs(int i, char *str);
int					skipnospacetabs(int i, char *str);
int					ft_atoi(const char *s);
unsigned int		to_big_endian(unsigned int nb, int size);
int					skiptoend(char *line, int i);

/*
**	strlib.c
*/
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strlen(const char *str);
int					ft_putstr_fd(int fd, const char *str);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(char *s1, char *s2, int len);

/*
**	ft_gnl.c
*/
int					ft_gnl(const int fd, char **line);

/*
**	ft_lstadd.c
*/
void				ft_lstadd(t_lstd **alst, const void *item, t_order order);

/*
**	get.c
*/
void				parse_code(t_all *all, int fd);
void				get_labels_and_size(t_all *all);

/*
**	write_line.c
*/
void				write_line(t_all *all, char *line, int opcode, int fd);

/*
**	isvalid.c
*/
int					is_valid_file(char *file);
#endif				/* !COREWAR_ASM_H */


