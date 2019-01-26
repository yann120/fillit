# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ypetitje <ypetitje@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 21:44:33 by ypetitje          #+#    #+#              #
#    Updated: 2019/01/26 12:48:00 by ypetitje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCDIR = SRC/

SRC = 	$(SRCDIR)fillit.c $(SRCDIR)get_next_line.c $(SRCDIR)grid.c\
		$(SRCDIR)helper.c $(SRCDIR)main.c $(SRCDIR)pieces.c\
		$(SRCDIR)validation.c

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)
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