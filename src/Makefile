#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhuhtane <hhuhtane@student.hive.f...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 14:52:52 by hhuhtane          #+#    #+#              #
#    Updated: 2020/06/02 12:21:37 by hhuhtane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf_obj

SRC = main.c ft_isometric.c ft_bresenham.c ft_color.c ft_tools.c ft_press1.c ft_press2.c ft_press3.c ft_press4.c ft_read.c ft_guide.c ft_tools2.c ft_press5.c

OBJ = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Wextra -Werror -c

FRAMEWORK = -o $(NAME) -I includes -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) -I ../includes
	@echo "SOURCES COMPILED TO OBJECTS!"

clean:
	@/bin/rm -f $(OBJ)
	@find . -type f -name '*~' -print -delete -o -name '#*#' -print -delete
	@echo "SRC/objects cleaned!"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "cleaned"

re: fclean all