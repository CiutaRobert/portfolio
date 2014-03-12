# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzak <jagu.sayan@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/02 22:13:03 by jzak              #+#    #+#              #
#    Updated: 2014/02/02 22:39:39 by jzak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=all

ifndef config
  config=release
endif
export config

PROJECTS := libft corewar asm

.PHONY: all clean help $(PROJECTS)

$(NAME): $(PROJECTS)

libft: 
	@echo "==== Building ft ($(config)) ===="
	@${MAKE} --no-print-directory -C libft -f Makefile

corewar: libft
	@echo "==== Building corewar ($(config)) ===="
	@${MAKE} --no-print-directory -C VM -f Makefile

asm:
	@echo "==== Building asm ===="
	@${MAKE} --no-print-directory -C asm -f Makefile

clean:
	@${MAKE} --no-print-directory -C libft -f Makefile clean
	@${MAKE} --no-print-directory -C VM -f Makefile clean
	@${MAKE} --no-print-directory -C asm -f Makefile clean

fclean:
	@${MAKE} --no-print-directory -C libft -f Makefile fclean
	@${MAKE} --no-print-directory -C VM -f Makefile fclean
	@${MAKE} --no-print-directory -C asm -f Makefile fclean

re:
	@${MAKE} --no-print-directory -C libft -f Makefile re
	@${MAKE} --no-print-directory -C VM -f Makefile re
	@${MAKE} --no-print-directory -C asm -f Makefile re

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "   release"
	@echo "   debug"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   fclean"
	@echo "   re"
	@echo "   libftft"
	@echo "   corewar"
	@echo ""
