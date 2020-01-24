
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 13:27:05 by hhuhtane          #+#    #+#              #
#    Updated: 2020/01/21 17:23:41 by hhuhtane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC_FLD = src/

SRC = main.c

OBJ = $(SRC: .c=.o)

DOIT = gcc -Wall -Wextra -Werror src/main.c libft/libft.a /usr/local/lib/libmlx.a -I includes -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror -I includes

FRAMEWORK = -framework OpenGL -framework AppKit

LIBFTX = ./libft/libft.a /usr/local/lib/libmlx.a

all: $(NAME)

$(NAME):
	@make -C libft
	@$(DOIT)
	@echo "READY TO GO!"

clean:
	@make -C libft clean
	@/bin/rm -f $(OBJ)
	@@find . -type f -name '*~' -print -delete -o -name '#*#' -print -delete

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)
	@echo "cleaned"

re:	fclean all
