/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 09:41:54 by gabtoubl          #+#    #+#             */
/*   Updated: 2014/01/26 13:42:00 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				FT_SH_H
# define			FT_SH_H
# define BUFF_SIZE	1024
typedef struct stat	t_stat;
typedef struct		s_path
{
	char			*path;
	int				len;
	struct s_path	*next;
}					t_path;
typedef struct		s_bltn
{
	char			*name;
	void			(*func)(char **, t_path **, char ***);
}					t_bltn;
int					exec_cmd(char *buf, t_path **list, char ***envp);
void				free_env(char **envp);
char				**copy_env(char **envp, char *line, int pos, int flag);
void				delete_one_from_env(char ***envp, int pos);
t_path				*get_paths(char **envp);
void				path_add(t_path **list, char *path, int len);
int					free_paths(t_path *list, int is_child);
int					parse_buf(char *buf, t_path *list, char **envp);
int					is_sep(char c, char *sep);
char				**ft_strsplit(char *buf, char *sep);
char				*check_redir(char *cmd);
int					redir_output(char *file, int end);
int					redir_input(char *file, int end);
int					check_pipe(char *cmd, t_path **list, char ***envp);
int					free_tab(char **tab);
int					is_builtin(char *buf, t_path **list, char ***envp);
void				ignore_all_signals(void);
void				handle_signal(int status);
void				go_oldpwd(char ***envp);
void				set_pwds(t_path **list, char ***envp);
void				cmd_setenv(char **tab, t_path **list, char ***envp);
int					ft_strlen(const char *str);
int					ft_putstr(int fd, const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, int n);
char				*ft_strjoin(const char *s1, const char *s2, char sep);
#endif				/* !FT_SH_H */
