# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 12:14:32 by javferna          #+#    #+#              #
#    Updated: 2021/10/26 18:27:03 by javferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src/
INC_DIR = inc/
INC_LIBFT_DIR = Libft/inc/

SRC	= $(addprefix $(SRC_DIR),	\
		main.c					\
		exit.c)

OBJ = $(SRC:.c=.o)

CC = gcc

INC = -I$(INC_DIR)

INC_LIBFT = -I$(INC_LIBFT_DIR)

CFLAGS = -Wall -Wextra -Werror $(INC) $(INC_LIBFT_DIR)

LIBFT = Libft/libft.a

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C Libft
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C Libft clean

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY = all clean fclean re
