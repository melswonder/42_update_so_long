# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hirwatan <hirwatan@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 20:50:51 by hirwatan          #+#    #+#              #
#    Updated: 2025/01/09 21:59:40 by hirwatan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBNAME = so_long.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = map_utils.c map_bucktrack.c map_delete_free.c map_new.c put_window.c setting_delete.c setting_new.c main.c map_check.c map.c
OBJS = $(SRCS:.c=.o)
MINILIBX = minilibx-linux/libmlx.a -L. -lXext -lX11

all: $(NAME) $(LIBNAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MINILIBX)
	chmod 777 $(NAME)

$(LIBNAME): $(OBJS)
	ar rcs $(LIBNAME) $(OBJS)
	chmod 777 $(LIBNAME)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(LIBNAME)

re: fclean all

v: $(NAME)
	valgrind --leak-check=full ./$(NAME)