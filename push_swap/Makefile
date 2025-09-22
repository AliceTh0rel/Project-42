# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: althorel <althorel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/04 14:54:09 by althorel          #+#    #+#              #
#    Updated: 2025/09/22 18:34:45 by althorel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHSWAP_FOLDER = src/

SRCS	= 	cost.c\
			ft_printf_utils.c\
			ft_printf.c\
			init_stack.c\
			instructions_a_b.c\
			instructions_a.c\
			instructions_b.c\
			instructions.c\
			main.c\
			move.c\
			parsing.c\
			sort_five.c\
			sort_simple.c\
			sort.c\
			split.c\
			target.c\
# les fichiers .c a compiler
OBJS	= ${SRCS:.c=.o}
#  convertir les .c en .o
INC = includes
# recherche dans le repertoire les .h
NAME	= push_swap
#  nom du dossier a la fin
CC	= cc
#  compiler
RM	= rm -f
#  supprimer les .o
CFLAGS	= -Wall -Wextra -Werror
#  flag de compilation
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(INC) $(OBJS) -o $(NAME)

%.o:	${PUSHSWAP_FOLDER}%.c
		${CC} ${CFLAGS} -I${INC} -c $< -o $@ 

clean:
		$(RM) $(OBJS)
# suppr les .o
fclean:	clean
	${RM} ${NAME} 
# suppr les anciens .a et .o
re: fclean
		make all
# recompile si besoin
.PHONY: re fclean clean all
# ce sont des commandes et non des fichiers
