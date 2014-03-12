#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabtoubl <gabtoubl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 10:32:52 by gabtoubl          #+#    #+#              #
#    Updated: 2014/02/09 04:34:44 by gabtoubl         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		ft_minishell3
SRCS=		main.c				\
			path.c				\
			buffer.c			\
			environ.c			\
			free.c				\
			builtins.c			\
			pwds.c				\
			redir.c				\
			in_out.c			\
			pipes.c				\
			split.c				\
			signal.c			\
			main_termcaps.c		\
			list.c				\
			history.c			\
			string.c			\
			init_stop.c			\
			move_and_reprint.c	\
			delete_char.c		\
			copy_paste.c		\
			abort.c				\
			cursor.c			\
			classic.c
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
