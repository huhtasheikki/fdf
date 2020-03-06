
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 13:27:05 by hhuhtane          #+#    #+#              #
#    Updated: 2020/03/06 10:13:47 by hhuhtane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC_FLD = src/

SRC = src/main.c src/ft_isometric.c src/ft_bresenham.c src/ft_color.c src/ft_tools.c src/ft_press1.c src/ft_press2.c src/ft_press3.c src/ft_read.c

AFILE = libft/libft.a /usr/local/lib/libmlx.a

OBJ = $(patsubst %.c, %.o, $(SRCS))

DOIT = gcc -Wall -Wextra -Werror src/main.c src/ft_draw_fdf.c src/ft_isometric.c src/ft_draw.c src/ft_bresenham.c libft/libft.a /usr/local/lib/libmlx.a -I includes -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror

FRAMEWORK = -I includes -framework OpenGL -framework AppKit

LIBFTX = ./libft/libft.a /usr/local/lib/libmlx.a

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) $(SRC) $(AFILE) $(FRAMEWORK)
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
