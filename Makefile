# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtran-nh <mtran-nh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 17:43:30 by mtran-nh          #+#    #+#              #
#    Updated: 2025/09/22 17:45:22 by mtran-nh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src/
INC_DIR = include/
LIBFT_DIR = Libft/
MLX_DIR = minilibx-linux/

SRCS = 	$(SRC_DIR)init.c \
		$(SRC_DIR)render.c \
		$(SRC_DIR)math.c \
		$(SRC_DIR)main.c \
		$(SRC_DIR)events.c \
		$(SRC_DIR)sierpinski.c \
		$(SRC_DIR)utils.c
		
OBJS = $(SRCS:.c=.o)

INCLUDES = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)
LIBS = -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -lX11 -lXext


all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re