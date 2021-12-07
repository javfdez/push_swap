# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 12:14:32 by javferna          #+#    #+#              #
#    Updated: 2021/12/07 20:16:26 by javferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src/
INC_DIR = inc/
INC_LIBFT_DIR = Libft/inc/
UTILS_DIR = utils/

SRC	= $(addprefix $(SRC_DIR),	\
		main.c					\
		parse.c					\
		index_stack.c			\
		find_moves.c			\
		final_moves.c			\
		small_numbers.c			\
		push_swap.c)

UTILS = $(addprefix $(UTILS_DIR),	\
		atoi.c						\
		exit_free.c					\
		str_fd0.c					\
		swap.c						\
		rotate.c					\
		push.c						\
		list_stack.c				\
		list_stack_2.c)

OBJ = $(SRC:.c=.o)

OBJ_UTILS = $(UTILS:.c=.o)

CC = gcc

INC = $(INC_DIR) $(INC_LIBFT_DIR)

INC_PARAMS = $(INC:%=-I%)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g $(INC_PARAMS)

LIBFT = Libft/libft.a

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_UTILS)
	$(MAKE) -C Libft
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_UTILS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_UTILS)
	$(MAKE) -C Libft clean

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY = all clean fclean re
