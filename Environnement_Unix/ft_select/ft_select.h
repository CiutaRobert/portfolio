/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 22:03:51 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/12 22:03:52 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef					FT_SELECT_H
# define				FT_SELECT_H
# define OK				(void *)1
# include				<termios.h>
typedef struct termios	t_term;
typedef struct winsize	t_win;
typedef struct			s_dbl
{
	int					x;
	int					y;
}						t_dbl;
typedef enum			e_opt
{
	CURSOR_MOVE=		0,
	UNDERLINE_ON=		1,
	UNDERLINE_OFF=		2,
	INVERTVIDEO_ON=		3,
	INVERTVIDEO_OFF=	4,
	HIDDEN_CURSOR=		5,
	VISIBLE_CURSOR=		6,
	TERM_INIT=			7,
	TERM_END=			8
}						t_opt;
typedef struct			s_list
{
	char				*str;
	int					len;
	int					idx;
	int					is_cur;
	int					is_select;
	struct s_list		*next;
	struct s_list		*prev;
}						t_list;
typedef struct			s_all
{
	int					fd;
	t_term				term;
	t_list				*full;
	int					last_elem;
	int					line;
	int					column;
	char				*opt[8];
}						t_all;
t_all					g_all;
int						ft_putchar2(int c);
int						ft_strlen(const char *str);
void					ft_putstr_fd(int fd, const char *str);
void					ft_cursor_down(t_all *all, t_dbl *pos);
void					ft_cursor_right(t_all *all, t_dbl *pos);
void					ft_cursor_left(t_all *all, t_dbl *pos);
void					get_sigwinch(int sig);
void					get_sigtstp(int sig);
void					get_sigcont(int sig);
void					get_other_sig(int sig);
void					handle_cursor(t_all *all, t_dbl *pos, char dir);
void					handle_select(t_all *all, t_list **choice, t_dbl *pos);
void					*puterror(const char *str);
void					lst_push_back(t_list **list, char *str, int idx);
int						lst_is_inside(t_list *list, int idx);
void					lst_del(t_list **list, int idx);
void					lst_aff(t_all *all);
void					lst_free(t_list **list);
char					*lst_check_error(t_all *all, t_dbl *pos);
char					*init_termcaps(t_all *all);
char					*stop_termcaps(t_all *all);
char					*init_all(t_all *all, int ac, char **av);
t_list					*lst_right(t_all *all, t_dbl *pos);
t_list					*lst_left(t_all *all, t_dbl *pos);
#endif					/* !FT_SELECT_H */
