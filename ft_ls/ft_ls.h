/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 20:29:43 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/15 20:05:58 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				FT_LS_H
# define			FT_LS_H
# define ON			1
# define OFF		0
# define OPTDONE	5
# define INFODONE	5
# define FIRST		0
# define LAST		1
# define PIVOT		2
# include			<sys/stat.h>
typedef				enum
{
	PRINT_HIDDEN =	0,
	LIST_DETAIL =	1,
	REVERSE_SORT =	2,
	TIME_SORT =		3,
	RECURSIVE =		4
}					t_opt;
typedef				enum
{
	HARD_LINK =		0,
	UID =			1,
	GID =			2,
	DEVICE =		3,
	SIZE =			4
}					t_info;
typedef struct		s_file
{
	char			*name;
	struct stat		*info;
	int				maxlen[INFODONE];
	struct s_file	*next;
	struct s_file	*prev;
}					t_file;
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putnbr(int n);
int					ft_strlen(const char *str);
char				*ft_strjoin(const char *s1, const char *s2);
t_file				*ft_lstnew(char *name, struct stat *info);
void				ft_lstpushback(t_file **list, t_file *new, char *opt);
t_file				*ft_lstlast(t_file *list);
int					ft_lstlen(t_file *list, char *opt);
void				ft_perror(const char *str);
void				aff_sorted_list(t_file *list, const char *path,
									int total, char *opt);
void				bubble_sort(t_file **list,
								int (*cmp)(t_file *elem1, t_file *elem2));
int					time_order(t_file *elem1, t_file *elem2);
int					classic_order(t_file *elem1, t_file *elem2);
int					parse_arg(int ac, char **av, char *opt);
void				set_all_off(char *opt);
void				print_mode(int file_mode);
void				print_hlink(int nb_link, t_file *list);
void				print_uid(int uid, t_file *list);
void				print_gid(int gid, t_file *list);
void				print_device(t_file *cur, t_file *list);
void				print_size(t_file *cur, t_file *list);
void				print_time(time_t *file_time);
void				print_slink(const char *path, const char *name);
void				*ft_memcpy(void *s1, const void *s2, int n);
int					ft_nblen(long int nb);
int					ft_strcmp(char *name1, char *name2);
int					is_nothidden(const char *path);
void				read_dir(char *path, char *opt);
void				option_l(t_file *list, int total, char *opt, char *path);
void				no_option(t_file *list, char *opt);
#endif				/* FT_LS_H */
