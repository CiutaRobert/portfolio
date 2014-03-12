/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 13:12:22 by cvxfous           #+#    #+#             */
/*   Updated: 2013/12/29 21:09:48 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				FT_SH_H
# define			FT_SH_H
# define BUFF_SIZE	1024
typedef struct		s_path
{
	char			*path;
	int				len;
	struct s_path	*next;
}					t_path;
typedef struct		s_bltn
{
	char			*name;
	void			(*func)(char **, char ***);
}					t_bltn;
t_path				*get_paths(char **envp);
int					free_paths(t_path *list, int is_child);
int					parse_buf(char *buf, t_path *list, char **envp);
char				**ft_strsplit(char *buf);
int					free_tab(char **tab);
int					is_builtin(char *buf, char ***envp);
void				ignore_all_signals(void);
void				handle_signal(int status);
int					ft_strlen(const char *str);
int					ft_putstr(int fd, const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, int n);
#endif				/* !FT_SH_H */
