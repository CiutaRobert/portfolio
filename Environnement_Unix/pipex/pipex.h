/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:33:18 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/30 13:52:08 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				PIPEX_H
# define			PIPEX_H
typedef struct		s_path
{
	char			*path;
	int				len;
	struct s_path	*next;
}					t_path;
int					parse_buf(char *buf, t_path *list, char **envp);
int					free_tab(char **tab, int ret);
t_path				*get_paths(char **envp);
int					free_paths(t_path *list, int is_child);
int					ft_strlen(const char *str);
int					ft_putstr(int fd, const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, int n);
#endif				/* !PIPEX_H */
