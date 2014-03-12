/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmokrane <nmokrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:42:04 by nmokrane          #+#    #+#             */
/*   Updated: 2014/01/15 18:42:08 by nmokrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		get_symbol(t_ptf_fmt_int *self, t_ptf_flags *f, char **result)
{
	self->symbol = '\0';
	if (TAG(*f, ' '))
		self->symbol = ' ';
	if (TAG(*f, '+'))
		self->symbol = '+';
	if (**result == '-')
	{
		ft_memmove(*result, ((*result) + 1), ft_strlen(*result));
		self->symbol = '-';
	}
}

static void		init_self(t_ptf_fmt_int *self, t_ptf_flags *f, char **result)
{
	self->fill_chr = ' ';
	if (f->length && f->length_zero && !f->precision && !f->precision_zero)
		self->fill_chr = '0';
	if (!f->length && !f->length_zero && f->precision && f->precision_zero)
		self->fill_chr = '0';
	self->empty = 0;
	if (STREQ(*result, "0")
			&& (f->precision < 0 || (!f->precision && f->precision_zero)))
	{
		**result = '\0';
		self->empty = 1;
	}
	get_symbol(self, f, result);
	self->fullsize = f->length;
	self->intsize = f->precision;
	if (!self->intsize)
	{
		self->intsize = f->length;
		if (self->fill_chr != '0')
			self->intsize = (int)ft_strlen(*result);
		else if (self->symbol)
			self->intsize--;
	}
}

static void		fill_str(char **result, int newsize, char fillchr)
{
	int					oldsize;
	char				*new;

	oldsize = ft_strlen(*result);
	if (ft_abs(newsize) <= oldsize)
		return ;
	new = ft_strnew(ft_abs(newsize));
	if (newsize < 0)
	{
		ft_memset(new, fillchr, ft_abs(newsize));
		ft_memcpy(new, *result, oldsize);
	}
	else
	{
		ft_memset(new, fillchr, ft_abs(newsize) - oldsize);
		ft_strcat(new, *result);
	}
	ft_strdel(result);
	*result = new;
}

void			ptf_fmt_int(t_ptf_flags *f, char **result)
{
	t_ptf_fmt_int		self;

	init_self(&self, f, result);
	if (self.intsize > 0)
		fill_str(result, self.intsize, '0');
	if (self.symbol)
		fill_str(result, (ft_strlen(*result) + 1), self.symbol);
	if (self.intsize < 0)
		fill_str(result, self.intsize, ' ');
	if (self.intsize > 0 && ft_abs(self.fullsize) > self.intsize)
		fill_str(result, self.fullsize, ' ');
	else if (self.empty && self.intsize >= 0)
		fill_str(result, self.fullsize, ' ');
}
