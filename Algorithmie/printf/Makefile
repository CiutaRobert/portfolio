#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 10:32:52 by gabtoubl          #+#    #+#              #
#    Updated: 2013/12/21 20:05:17 by gabtoubl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		libftprintf.a
SRCS=		main.c			\
			stk_printf.c	\
			stk_number.c	\
			stk_string.c	\
			string.c		\
			list.c			\
			flag.c
OBJS=		$(SRCS:.c=.o)
CFLAGS=		-Wall -Wextra -Werror -g
CC=			gcc
LIB=		ar rc
RM=			rm -f

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
