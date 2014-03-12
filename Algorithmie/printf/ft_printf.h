/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 18:44:37 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/21 20:07:05 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				FT_PRINTF_H
# define			FT_PRINTF_H
# define MAX(x, y)	(x < y ? y : x)
# define SPECDONE	11
typedef				enum
{
    INTEGER,
    U_INTEGER,
    CHAR,
    CHAR_PTR,
    CHAR_PTRSP,
    VOID_PTR
}					t_type;
typedef struct		s_flag
{
  int				plus;
  int				minus;
  int				space;
  int				sharp;
  int				zero;
  int				width;
}					t_flag;
typedef struct		s_list
{
  void				*content;
  t_type			type;
  char				*base;
  t_flag			*flag;
  int				len;
  int				flag_len;
  struct s_list		*next;
}					t_list;
typedef struct		s_ptr
{
  char				letter;
  t_type			type;
  char				*base;
  void				(*func)(t_list *, char *, int);
}					t_ptr;
int					ft_printf(const char *format, ...);
int					ft_strlen(const char *str);
int					ft_strlensp(const char *str);
void				ft_putstr(const char *str);
void				ft_putprintf(const char *strout, int len);
t_list				*new_elem(void *content, t_type type,
						char *base, t_flag *flag);
void				push_back(t_list **list, t_list *new);
void				init_flag(const char *format, int *pos, t_flag *flag);
int					flag_length(t_list *elem);
void				flag_aff(t_list *elem, char *strout, int pos);
void				flag_spaces(t_list *elem, char *strout, int *pos);
int					nb_len(long int nb, char *base);
void				get_ptrs(t_ptr *ptr);
void				stk_printf(const char *strin, char *strout, t_list *list);
void				stk_nbr(long int nb, char *base, char *strout, int pos);
void				stk_addrnbr(unsigned long nb, char *base,
								char *strout, int pos);
void				stk_int(t_list *elem, char *strout, int pos);
void				stk_uint(t_list *elem, char *strout, int pos);
void				stk_char(t_list *elem, char *strout, int pos);
void				stk_addr(t_list *elem, char *strout, int pos);
void				stk_str(t_list *elem, char *strout, int pos);
void				stk_strsp(t_list *elem, char *strout, int pos);
#endif				/* !FT_PRINT_H */
