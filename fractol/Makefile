# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: althorel <althorel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 13:34:54 by althorel          #+#    #+#              #
#    Updated: 2025/09/22 19:32:18 by althorel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

CC			= cc
CFLAGS		= -Wextra -Wall -Werror -g3

MLX_DIR		= ./minilibx-linux/
MLX         = $(MLX_DIR)mlx.h

FRACTOL_FOLDER = src/

SRCS		=	main.c\
				ft_printf.c\
				ft_printf_utils.c\
				libft.c\
				init_img.c\
				calcul.c\
				hooks.c\
				init_window.c\
				psy_color_1.c\
				psy_color_2.c\

INCLUDES	= -I includes -I $(MLX_DIR)
LIBS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz \

OBJS	= ${SRCS:.c=.o}

all: $(NAME)

%.o: ${FRACTOL_FOLDER}%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX) :
	curl -L -o minilibx-linux.tgz https://cdn.intra.42.fr/document/document/35013/minilibx-linux.tgz
	tar -xvf minilibx-linux.tgz
	rm -f minilibx-linux.tgz

$(NAME): ${MLX} $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -rf $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
		make all

.PHONY: all, clean, fclean, re
