# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 18:23:18 by anaraujo          #+#    #+#              #
#    Updated: 2023/01/12 19:00:06 by anaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := cc
CFLAGS := -Wall -Werror -Wextra -g
MLXFLAGS := -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

SRCS := main.c	

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lm $(SRCS) $(MLXFLAGS) -o $(NAME)
	
clean:
		rm -rf $(OBJS)

fclean:
		rm -rf $(NAME)

re: fclean all