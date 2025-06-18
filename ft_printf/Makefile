# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: althorel <althorel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 10:53:08 by althorel          #+#    #+#              #
#    Updated: 2025/05/16 15:27:12 by althorel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= 	ft_printf.c\
			ft_put.c\
			ft_putnbr_other.c\
# les fichiers .c a compiler
OBJS	= ${SRCS:.c=.o}
#  convertir les .c en .o
INC = includes
# recherche dans le repertoire les .h
NAME	= libftprintf.a
#  nom du dossier a la fin
CC	= cc
#  compiler
RM	= rm -f
#  supprimer les .o
CFLAGS	= -Wall -Wextra -Werror
#  flag de compilation
all: $(NAME)
# commande generale
$(NAME):	$(OBJS)
		ar -rcs $@ $^ 
# ^prends ttes les dependances // < que le premier // ar pour creer la librairie 
# $@ appel la cible et $^ ou $< appel la dependance 
# $@ = $ $(NAME)
%.o:	%.c
		${CC} ${CFLAGS} -I${INC} -c $< -o $@ 
# cible / dependance / commande
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
