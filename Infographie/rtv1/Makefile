#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 10:32:52 by gabtoubl          #+#    #+#              #
#    Updated: 2014/02/15 00:45:58 by gabtoubl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		rtv1
SRCS=		main.c		\
			calc.c		\
			light.c		\
			shadow.c	\
			colors.c	\
			rotate.c	\
			inter_obj.c	\
			draw.c		\
			list.c		\
			string.c	\
			handler.c
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
