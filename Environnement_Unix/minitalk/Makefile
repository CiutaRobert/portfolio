#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 10:32:52 by gabtoubl          #+#    #+#              #
#    Updated: 2014/02/08 14:01:19 by gabtoubl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME1=		client
NAME2=		serveur
SRCS1=		client.c		\
			basic_func.c
SRCS2=		server.c		\
			basic_func.c
OBJS1=		$(SRCS1:.c=.o)
OBJS2=		$(SRCS2:.c=.o)
CFLAGS=		-Wall -Wextra -Werror
CC=			gcc
RM=			rm -f

all:		$(NAME1) $(NAME2)

$(NAME1):	$(OBJS1)
			$(CC) -o $(NAME1) $(OBJS1)

$(NAME2):	$(OBJS2)
			$(CC) -o $(NAME2) $(OBJS2)

clean:
			$(RM) $(OBJS1) $(OBJS2)

fclean:		clean
			$(RM) $(NAME1) $(NAME2)

re:			fclean all

.PHONY:		all clean fclean re
