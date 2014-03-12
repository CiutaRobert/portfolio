#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 13:30:17 by gabtoubl          #+#    #+#              #
#    Updated: 2014/01/12 21:58:57 by gabtoubl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		ft_select
SRCS=		main.c			\
			cursor.c		\
			signal.c		\
			string.c		\
			list.c			\
			free.c			\
			error_aff.c		\
			handle_select.c	\
			print_list.c	\
			init_stop.c
OBJS=		$(SRCS:.c=.o)
CFLAGS=		-Wall -Wextra -Werror
LIB=		-ltermcap
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
