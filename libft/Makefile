#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 11:39:33 by hhuhtane          #+#    #+#              #
#    Updated: 2020/02/22 10:35:12 by hhuhtane         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS = ft_putchar.c ft_memset.c ft_putendl.c ft_putnbr.c ft_putstr.c ft_strlen.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_memalloc.c ft_atoi.c ft_memmove.c ft_memcmp.c ft_memdel.c ft_strnew.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strdel.c ft_strclr.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c get_next_line.c ft_array_len.c ft_atoi_base.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

HEADERS = ./

FLAGS = -Wall -Wextra -Werror -I$(HEADERS)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "LIBFT is ready!"

clean:
	@rm -f $(OBJS)
	@find . -type f -name '*~' -print -delete -o -name '#*#' -print -delete
	@echo "LIBFT objects cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "LIBFT totally cleaned"

re: fclean all