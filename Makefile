# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 21:44:33 by ypetitje          #+#    #+#              #
#    Updated: 2019/01/26 13:20:21 by ypetitje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit


SRC = 	SRC/fillit.c SRC/get_next_line.c SRC/grid.c\
		SRC/helper.c SRC/main.c SRC/pieces.c\
		SRC/validation.c

OBJ =	SRC/fillit.o SRC/get_next_line.o SRC/grid.o\
		SRC/helper.o SRC/main.o SRC/pieces.o\
		SRC/validation.o
CFLAGS = -Wall -Wextra -Werror
# OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -c $(CFLAGS) $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIBFT)

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
	git pull 42 master
	git pull github master

push:
	git push 42 master
	git push github master

sync: pull push 

.PHONY : all clean fclean re