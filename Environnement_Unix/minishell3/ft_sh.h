/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 09:41:54 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/02/09 03:54:45 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef					FT_SH_H
# define				FT_SH_H
# define OK				0
# define NOT_OK			1
# define SEND_LINE		2
# define BUFF_SIZE		10000
# include				<termios.h>
typedef struct termios	t_term;
typedef struct stat		t_stat;
typedef enum			e_caps
{
	MOVE_LEFT =			0,
	MOVE_RIGHT =		1,
	CLEAR_EOL =			2
}						t_caps;
typedef struct			s_list
{
	char				*str;
	struct s_list		*next;
	struct s_list		*prev;
}						t_list;
typedef struct			s_all
{
	int					cursor_x;
	int					cursor_y;
	int					max_y;
	t_term				term;
	t_list				*list;
	char				line[BUFF_SIZE];
	char				save[BUFF_SIZE];
	char				*caps[3];
}						t_all;
typedef struct			s_func
{
	int					code;
	void				(*func)(t_all *);
}						t_func;
typedef struct			s_path
{
	char				*path;
	int					len;
	struct s_path		*next;
}						t_path;
typedef struct			s_bltn
{
	char				*name;
	void				(*func)(char **, t_path **, char ***);
}						t_bltn;
int						exec_cmd(char *buf, t_path **list, char ***envp);
void					free_env(char **envp);
char					**copy_env(char **envp, char *line, int pos, int flag);
void					delete_one_from_env(char ***envp, int pos);
t_path					*get_paths(char **envp);
void					path_add(t_path **list, char *path, int len);
int						free_paths(t_path *list, int is_child);
int						parse_buf(char *buf, t_path *list, char **envp);
int						is_sep(char c, char *sep);
char					**ft_strsplit(char *buf, char *sep);
char					*check_redir(char *cmd);
int						redir_output(char *file, int end);
int						redir_input(char *file, int end);
int						check_pipe(char *cmd, t_path **list, char ***envp);
int						free_tab(char **tabs);
int						is_builtin(char *buf, t_path **list, char ***envp);
void					ignore_all_signals(void);
void					handle_signal(int status);
void					go_oldpwd(char ***envp);
void					set_pwds(t_path **list, char ***envp);
void					cmd_setenv(char **tabs, t_path **list, char ***envp);
int						ft_putstr_fd(int fd, const char *str);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, int n);
char					*ft_strjoin(const char *s1, const char *s2, char sep);
int						ft_putchar(int c);
void					ft_putstr(const char *str);
int						ft_strlen(const char *str);
char					*ft_strcpy(char *src, char *dest);
void					handle_cursor(t_all *all, char *buf);
int						puterror(const char *str);
int						main_termcaps(t_all *all);
int						init_termcaps(t_all *all);
int						stop_termcaps(t_all *all);
t_list					*lst_new(char *str);
void					lst_pushback(t_list **list, char *str);
void					history_prev(t_all *all);
void					history_next(t_all *all);
void					move_cursor_left(t_all *all);
void					reprint_line(t_all *all);
void					insert_char(t_all *all, char c);
void					del_char(t_all *all);
void					del_prev_char(t_all *all);
void					go_start(t_all *all);
void					go_end(t_all *all);
void					cut_line(t_all *all);
void					paste_line(t_all *all);
int						send_exit(t_all *all);
#endif					/* !FT_SH_H */
