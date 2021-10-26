# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javferna <javferna@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 12:14:32 by javferna          #+#    #+#              #
#    Updated: 2021/10/26 12:14:34 by javferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR	=	src/
UTILS_DIR = utils/
INC_DIR	=	inc/

SRC	=	$(addprefix $(SRC_DIR),	\
		ft_printf.c			\
		ft_check_char.c		\
		ft_check_str.c		\
		ft_check_int.c		\
		ft_check_uns.c		\
		ft_check_pointer.c	\
		ft_check_hex.c)

UTILS	=	$(addprefix $(UTILS_DIR),	\
		ft_strlen.c		\
		ft_putchar.c	\
		ft_putnbr_base.c)

OBJ = $(SRC:.c=.o)

OBJ_UTILS = $(UTILS:.c=.o)

AR = ar rcs

CC = gcc

INC = -I$(INC_DIR)

CFLAGS = -Wall -Wextra -Werror $(INC)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_UTILS)
	$(AR) $(NAME) $(OBJ) $(OBJ_UTILS)

clean:
	$(RM) $(OBJ) $(OBJ_UTILS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re
