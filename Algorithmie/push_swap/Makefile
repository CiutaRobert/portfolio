#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvxfous <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/24 02:15:09 by cvxfous           #+#    #+#              #
#    Updated: 2013/12/29 19:01:32 by gabtoubl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		push_swap
SRCS=		main.c			\
			algo.c			\
			list.c			\
			classic.c
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
