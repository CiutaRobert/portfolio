#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 10:32:52 by gabtoubl          #+#    #+#              #
#    Updated: 2014/01/26 11:11:33 by gabtoubl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		ft_minishell2
SRCS=		main.c		\
			path.c		\
			buffer.c	\
			environ.c	\
			free.c		\
			builtins.c	\
			pwds.c		\
			redir.c		\
			in_out.c	\
			pipes.c		\
			split.c		\
			signal.c	\
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
