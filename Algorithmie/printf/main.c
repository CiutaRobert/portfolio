/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 18:55:32 by gabtoubl          #+#    #+#             */
/*   Updated: 2013/12/21 20:38:26 by gabtoubl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		<stdarg.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		<stdio.h>
#include		"ft_printf.h"

void			get_ptrs(t_ptr *ptr)
{
	int			i;
	t_ptr		spec[SPECDONE] =
		{{'d', INTEGER, "0123456789", &stk_int},
		{'i', INTEGER, "0123456789", &stk_int},
		{'b', U_INTEGER, "01", &stk_uint},
		{'u', U_INTEGER, "0123456789", &stk_uint},
		{'o', U_INTEGER, "01234567", &stk_uint},
		{'x', U_INTEGER, "0123456789abcdef", &stk_uint},
		{'X', U_INTEGER, "0123456789ABCDEF", &stk_uint},
		{'p', VOID_PTR, "0123456789abcdef", &stk_addr},
		{'c', CHAR, NULL, &stk_char},
		{'s', CHAR_PTR, NULL, &stk_str},
		{'S', CHAR_PTRSP, NULL, &stk_strsp}};

	i = -1;
	while (++i < SPECDONE)
		ptr[i] = spec[i];
}

static int	add_spec(const char *strin, int *pos,
					 va_list *vlist, t_list **list)
{
	int		i;
	t_ptr	ptr[SPECDONE];
	t_flag	flag;
	t_list	*tmp;

	get_ptrs(ptr);
	init_flag(strin, pos, &flag);
	tmp = NULL;
	i = -1;
	while (++i < SPECDONE && !tmp)
	{
		if (strin[*pos] == ptr[i].letter)
		{
			tmp = new_elem(va_arg(*vlist, void *), ptr[i].type,
							ptr[i].base, &flag);
			push_back(list, tmp);
			return (MAX((tmp->len + tmp->flag_len), (tmp->flag->width)));
		}
	}
	return (1);
}

int			ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	vlist;
	t_list	*list;
	char	*strout;

	va_start(vlist, format);
	list = NULL;
	len = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && (++i))
			len += add_spec(format, &i, &vlist, &list);
		else
			++len;
	}
	va_end(vlist);
	if ((strout = malloc(sizeof(char) * (len + 1))) == NULL)
		return (-1);
	strout[len] = 0;
	stk_printf(format, strout, list);
	ft_putprintf(strout, len);
	return (len);
}
