#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 10:32:52 by gabtoubl          #+#    #+#              #
#    Updated: 2014/01/17 10:14:27 by gabtoubl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		wolf3d
SRCS=		main.c		\
			init.c		\
			laby.c		\
			calc.c		\
			draw.c		\
			string.c	\
			handler.c	\
			minimap.c	\
			minecraft.c
OBJS=		$(SRCS:.c=.o)
LIB=		-L/usr/X11/lib -lmlx -lXext -lX11 -lm
CFLAGS=		-Wall -Wextra -Werror -I/usr/X11/include/
CC=			gcc
RM=			rm -f

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LIB)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
