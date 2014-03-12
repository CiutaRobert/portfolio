#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 10:32:52 by gabtoubl          #+#    #+#              #
#    Updated: 2013/12/15 20:04:58 by gabtoubl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		ft_ls
SRCS=		main.c		\
			str.c		\
			option_l.c	\
			list.c		\
			sort.c		\
			error.c		\
			parser.c	\
			misc.c		\
			print1.c	\
			print2.c
OBJS=		$(SRCS:.c=.o)
CFLAGS=		-Wall -Wextra -Werror
CC=			gcc
RM=			rm -f

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
