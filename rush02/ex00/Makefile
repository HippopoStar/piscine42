# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgauther <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 21:50:28 by vgauther          #+#    #+#              #
#    Updated: 2017/07/23 22:32:33 by vgauther         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2
NAME0 = colle-00
NAME1 = colle-01
NAME2 = colle-02
NAME3 = colle-03
NAME4 = colle-04

SRC = ft_atoi.c ft_putchar.c ft_putnbr.c affiche.c
SRC2 = ft_atoi.c ft_putchar.c ft_putnbr.c affiche.c str_00.c str_01.c str_02.c str_03.c str_04.c

all: compiler

compiler2:
	gcc -c ft_atoi.c
	ar rc libft.a *.o
	ranlib libft.a

compiler:
	gcc -o $(NAME) main.c $(SRC2)
	gcc -o $(NAME0) rush00.c $(SRC)
	gcc -o $(NAME1) rush01.c $(SRC)
	gcc -o $(NAME2) rush02.c $(SRC)
	gcc -o $(NAME3) rush03.c $(SRC)
	gcc -o $(NAME4) rush04.c $(SRC)

clean:
	rm -f ft_atoi.o

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME0)
	rm -f $(NAME1)
	rm -f $(NAME2)
	rm -f $(NAME3)
	rm -f $(NAME4)

re: fclean all
