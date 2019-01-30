# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwuensch <fwuensch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 21:44:33 by ypetitje          #+#    #+#              #
#    Updated: 2019/01/30 19:37:46 by fwuensch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = 	srcs/fillit.c srcs/get_next_line.c srcs/grid.c\
		srcs/helper.c srcs/main.c srcs/pieces.c\
		srcs/validations_part_1.c srcs/validations_part_2.c

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

commit:
	git add .
	git commit -m "On avance! (ce commit a été créé automatiquement)"

pull:
	git pull github master
	git pull retry1 master
	git pull 42 master

push:
	git push github master
	git push retry1 master
	git push 42 master

sync: pull push

.PHONY : all clean fclean re
