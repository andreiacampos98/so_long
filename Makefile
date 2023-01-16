# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 18:23:18 by anaraujo          #+#    #+#              #
#    Updated: 2023/01/16 20:12:14 by anaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := cc
CFLAGS := -Wall -Werror -Wextra -g
MLXFLAGS := -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

LIBFT = ./libft/libft.a

SRCS := main.c					\
			map_build_tile.c	\
			map_check.c			\
			map_check_2.c		\
			map_read.c			\
			map_utils.c			\
			utils.c				

OBJS := $(SRCS:.c=.o)

$(LIBFT):
	$(MAKE) -C ./libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -lm $(SRCS) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	
clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJS)

fclean:
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re: fclean all