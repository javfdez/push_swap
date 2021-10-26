# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 12:14:32 by javferna          #+#    #+#              #
#    Updated: 2021/10/26 21:13:06 by javferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src/
INC_DIR = inc/
INC_LIBFT_DIR = Libft/inc/

SRC	= $(addprefix $(SRC_DIR),	\
		main.c					\
		exit_free.c)

OBJ = $(SRC:.c=.o)

CC = gcc

INC = $(INC_DIR) $(INC_LIBFT_DIR)

INC_PARAMS = $(INC:%=-I%)

CFLAGS = -Wall -Wextra -Werror $(INC_PARAMS)

LIBFT = Libft/libft.a

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C Libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C Libft clean

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY = all clean fclean re
