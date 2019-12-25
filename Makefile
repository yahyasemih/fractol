# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yez-zain <yez-zain@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/25 14:36:35 by yez-zain          #+#    #+#              #
#    Updated: 2019/12/25 16:36:23 by yez-zain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c tools.c complex.c events.c fractals.c

OBJ = main.o tools.o complex.o events.o fractals.o

all:$(NAME)

$(NAME): $(OBJ)
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@gcc -o $(NAME) $(OBJ) -l mlx -framework OpenGL -framework AppKit

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all