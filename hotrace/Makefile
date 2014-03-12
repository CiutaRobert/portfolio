#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/13 20:02:45 by gabtoubl          #+#    #+#              #
#    Updated: 2013/12/15 21:49:42 by gabtoubl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		hotrace
SRCS=		main.c		\
			gnl.c		\
			string.c	\
			btree.c		\
			comp.c
OBJS=		$(SRCS:.c=.o)
CFLAGS=		-Wall -Wextra -Werror -O2
CC=			/usr/bin/gcc
RM=			/bin/rm -f

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean
