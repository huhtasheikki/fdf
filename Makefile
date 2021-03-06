#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 13:27:05 by hhuhtane          #+#    #+#              #
#    Updated: 2020/03/12 10:30:50 by hhuhtane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = src/main.c src/ft_isometric.c src/ft_bresenham.c src/ft_color.c src/ft_tools.c src/ft_press1.c src/ft_press2.c src/ft_press3.c src/ft_press4.c src/ft_read.c src/ft_guide.c src/ft_tools2.c src/ft_press5.c

AFILE = libft/libft.a /usr/local/lib/libmlx.a

OBJ = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror

FRAMEWORK = -o $(NAME) -I includes -framework OpenGL -framework AppKit

LIBFTX = ./libft/libft.a /usr/local/lib/libmlx.a

all: $(NAME)

$(NAME):
	@make -C libft
	@make -C src
	@gcc $(FLAGS) $(OBJ) $(AFILE) $(FRAMEWORK)
	@echo "READY TO GO!"

clean:
	@make -C libft clean
	@make -C src clean
	@rm -f $(OBJ)
	@find . -type f -name '*~' -print -delete -o -name '#*#' -print -delete
	@echo "Objects cleaned"

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)
	@echo "Totally cleaned"

re:	fclean all
