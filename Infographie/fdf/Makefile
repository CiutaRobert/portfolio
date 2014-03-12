#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 10:32:52 by gabtoubl          #+#    #+#              #
#    Updated: 2013/12/21 18:11:50 by gabtoubl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		fdf
SRCS=		main.c		\
			fdf.c		\
			map.c		\
			lib.c
OBJS=		$(SRCS:.c=.o)
LIB=		-L/usr/X11/lib -lmlx -lXext -lX11
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
