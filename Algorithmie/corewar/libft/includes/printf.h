/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:31:58 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 18:44:06 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include "dynbuf.h"

# define FTPRINTF_BUFF_SIZE 64

# define STREQ(s1, s2) (ft_strcmp(s1, s2) == 0)

# define TAGS_LIST "hljtzqL#-+ "
# define IS_TAG(c) (c != '\0' && ft_strchr(TAGS_LIST, c))
# define IS_NBR(c) (c == '.' || c == '*' || c == '-' || ft_isdigit(c))
# define IS_FLAG(c) (IS_NBR(c) || IS_TAG(c) || get_type_fn(c))

# define TAG(flags, token) (ft_strcount((flags).tags, token))
# define ZERO(flags) ((flags).length_zero || (flags).precision_zero)

/*
** Flag structure for advanced formatting
*/
typedef struct		s_ptf_flags
{
	int				length;
	int				length_zero;
	int				precision;
	int				precision_zero;
	char			*tags;
}					t_ptf_flags;

/*
** Type structure, for static events array
*/
typedef char *(*t_ptf_type_fn)(t_ptf_flags f, va_list ap);
typedef struct		s_ptf_type
{
	char			label;
	t_ptf_type_fn	function;
}					t_ptf_type;

/*
** Structures for type specific advanced formatting
*/
typedef struct		s_ptf_fmt_int
{
	char			symbol;
	char			fill_chr;
	int				intsize;
	int				fullsize;
	int				empty;
}					t_ptf_fmt_int;

/*
** Callable printf functions
*/
int			ft_vdprintf(int fd, const char *format, va_list ap);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_printf(const char *format, ...);

/*
** Printf core function
*/
void		ptf_putarg(t_dynbuf *buf, const char **astr, va_list ap);

/*
** Type specific advanced formatting functions
*/
void		ptf_fmt_int(t_ptf_flags *f, char **result);

/*
** type functions
*/
char		*ptf_type_d(t_ptf_flags f, va_list ap);
char		*ptf_type_D(t_ptf_flags f, va_list ap);
char		*ptf_type_u(t_ptf_flags f, va_list ap);
char		*ptf_type_U(t_ptf_flags f, va_list ap);

char		*ptf_type_o(t_ptf_flags f, va_list ap);
char		*ptf_type_O(t_ptf_flags f, va_list ap);
char		*ptf_type_p(t_ptf_flags f, va_list ap);
char		*ptf_type_x(t_ptf_flags f, va_list ap);
char		*ptf_type_X(t_ptf_flags f, va_list ap);

char		*ptf_type_s(t_ptf_flags f, va_list ap);
char		*ptf_type_c(t_ptf_flags f, va_list ap);
char		*ptf_type_perc(t_ptf_flags f, va_list ap);

#endif /* !PRINTF_H */
