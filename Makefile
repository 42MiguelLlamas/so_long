# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mllamas- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 17:20:49 by mllamas-          #+#    #+#              #
#    Updated: 2023/12/19 18:46:10 by mllamas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = main.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -Imlx

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
