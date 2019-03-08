# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scao <scao@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 10:51:02 by scao              #+#    #+#              #
#    Updated: 2019/03/08 08:26:25 by scao             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBFT = libft

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c \
	  check_input.c \
	  ft_error.c \
	  ft_usage.c \
	  check_j.c \
	  backtracking.c \
	  valid.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(SRC) libft/libft.a -o $(NAME)
	@echo "Fillit is READY!"

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ)
	@echo "Object files cleared!"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@echo "All clean!"

re: fclean all

.PHONY: all clean fclean all

