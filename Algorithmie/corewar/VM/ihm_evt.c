/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ihm_evt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 16:21:27 by jzak              #+#    #+#             */
/*   Updated: 2014/01/31 12:24:10 by jzak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VM.h"

void			pause_evt(void *data)
{
	(void)data;
	if (ihm.status == RUN)
		ihm.status = PAUSE;
	else
		ihm.status = RUN;
}

void			info_evt(void *data)
{
	(void)data;
	if (panel_hidden(ihm.panels[0]))
		show_panel(ihm.panels[0]);
	else
		hide_panel(ihm.panels[0]);
}

void			print_evt(void *data)
{
	(void)data;
	if (panel_hidden(ihm.panels[1]))
		show_panel(ihm.panels[1]);
	else
		hide_panel(ihm.panels[1]);
}

void			step_evt(void *data)
{
	(void)data;
	ihm.status = STEP;
}

void			quit_evt(void *data)
{
	(void)data;
	ihm.status = QUIT;
}
