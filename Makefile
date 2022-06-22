# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 12:09:18 by gissao-m          #+#    #+#              #
#    Updated: 2022/06/22 11:13:32 by gissao-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

HEADER = ./get_next_line.h

SRCS = ./get_next_line_utils.c \
		 ./get_next_line.c \
		
CFLAGS =  -Wall -Wextra -Werror

CC = gcc

OBJS = ${SRCS:.c=.o}

all:        $(NAME)

$(NAME):    $(OBJS) $(BONUS_O)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:

	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all