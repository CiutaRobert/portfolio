/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 15:31:39 by jzak              #+#    #+#             */
/*   Updated: 2014/01/29 19:10:31 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_H
# define NCURSES_H

# define ECHAP 27

# include <curses.h>
# include "op.h"

typedef void (*t_ihm_fn) (void*);

typedef struct		s_curses_evt
{
	int				evt;
	t_ihm_fn		fn;
}					t_curses_evt;

t_bool			init_curses(void);
void			handle_key_event(t_curses_evt *evt, void *data);
void			destroy_curses(void);

#endif /* !NCURSES_H */
