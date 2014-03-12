#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fflorens <fflorens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/08 06:21:12 by fflorens          #+#    #+#              #
#    Updated: 2014/01/29 22:23:49 by fflorens         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC		=	gcc
CFLAGS  =	-Wall -Werror -Wextra -pedantic -ansi -g
NAME   	=	asm
PROJ    =	COREWAR_ASM
INCDIR	=	includes
SRCDIR  =	srcs
OBJDIR  =	objs
SRC		=	corelib.c		\
			ft_gnl.c		\
			ft_lstadd.c		\
			strlib.c		\
			main.c			\
			list.c			\
			get.c			\
			isvalid.c		\
			writeline.c

OBJ	 	=	$(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

.PHONY: all clean fclean re $(LIB)

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "[$(PROJ)]: Assembling $(NAME)"
	@$(CC) $(OBJ) -o $(NAME)
	@echo "[$(PROJ)]: Done !"

$(OBJDIR)/%.o : $(addprefix $(SRCDIR)/, %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $^ -I $(INCDIR)

clean :
	@echo "[$(PROJ)]: Deleting objects"
	@rm -rf $(OBJ)
	@rm -rf $(OBJDIR)
	@echo "[$(PROJ)]: Done !"

fclean : clean
	@echo "[$(PROJ)]: Deleting $(NAME)"
	@rm -f $(NAME)
	@echo "[$(PROJ)]: Done !"

re : fclean all
