# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsalome <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 23:23:23 by vsalome           #+#    #+#              #
#    Updated: 2017/07/26 21:14:19 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-I./

NAME = bsq

SRC = main_bsq.c\
	  bsq_files.c\
	  map_constructor.c\
	  from_map_to_perl_set.c\
	  solve.c\
	  print.c\
	  ft_atoi.c\
	  liberator.c\
	  check_error.c

OBJS = main_bsq.o\
	  bsq_files.o\
	  map_constructor.o\
	  from_map_to_perl_set.o\
	  solve.o\
	  print.o\
	  ft_atoi.o\
	  liberator.o\
	  check_error.o

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(SRC)
	gcc -o $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY	:	all clean fclean re
