# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: althorel <althorel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 17:27:20 by althorel          #+#    #+#              #
#    Updated: 2025/09/15 20:13:19 by althorel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strncmp.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_striteri.c\
			ft_strmapi.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_itoa.c\
			ft_split.c\
			
SRCBON	=	ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstmap_bonus.c\
# les fichiers .c a compiler
OBJS	= ${SRCS:.c=.o}
#  convertir les .c en .o
OBJBON	= ${SRCBON:.c=.o}

INC = includes
# recherche dans le repertoire les .h
NAME	= libft.a
#  nom du dossier a la fin
CC	= cc
#  compiler
COLOUR_GREEN	=	\033[0;32m

COLOUR_END		=	\033[0m

RM	= rm -f
#  supprimer les .o
CFLAGS	= -Wall -Wextra -Werror
#  flag de compilation
all: $(NAME)
# commande generale
$(NAME):	$(OBJS)
		@ar -rcs $@ $^ 
# ^prends ttes les dependances // < que le premier // ar pour creer la librairie 
# $@ appel la cible et $^ ou $< appel la dependance 
# $@ = $ $(NAME)
%.o:	%.c
		@${CC} ${CFLAGS} -I${INC} -c $< -o $@ 
		
bonus: $(OBJBON)
		@ar -rcs ${NAME} $^ 
# cible / dependance / commande
clean:
		@$(RM) $(OBJS) $(OBJBON)
# suppr les .o
fclean:	clean
	@${RM} ${NAME}
	@echo "${COLOUR_GREEN}Libft cleaned\n${COLOUR_END}"
# suppr les anciens .a et .o
re: fclean
		make all
# recompile si besoin
.PHONY: re fclean clean all bonus
# ce sont des commandes et non des fichiers
