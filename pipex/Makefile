# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: althorel <althorel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 16:48:48 by althorel          #+#    #+#              #
#    Updated: 2025/09/22 18:16:25 by althorel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex

NAME_BONUS		=	pipex_bonus

CFLAGS			=	-Wall -Wextra -Werror -I ${INCLD_DIR} -g3

CC				=	cc

COLOUR_GREEN	=	\033[0;32m

COLOUR_END		=	\033[0m

# **************************************************************************** #
#                                                                              #
#                                  LIBFT                                       #
#                                                                              #
# **************************************************************************** #

LIB				=	libft.a

LIBFT_FOLDER 	=	libft/

LIB_SOURCES		=	${LIBFT_FOLDER}*.c

LIB_INCLD		= 	${LIBFT_FOLDER}libft.h

LIB_PATH		=	libft/libft.a

# **************************************************************************** #
#                                                                              #
#                                  SOURCES                                     #
#                                                                              #
# **************************************************************************** #

SOURCES_PATH	=	srcs/

SOURCES_MAIN	= 	main.c \
					routine_child.c \
					path_child.c \
					infile_child.c \
					exit.c \

# **************************************************************************** #
#                                                                              #
#                                  OBJECTS                                     #
#                                                                              #
# **************************************************************************** #

OBJECTS_PATH	=	objs/

OBJECTS			=	$(addprefix ${OBJECTS_PATH}, ${SOURCES_MAIN:.c=.o}) \


# **************************************************************************** #
#                                                                              #
#                                  INCLUDES                                    #
#                                                                              #
# **************************************************************************** #

INCLD_DIR		=	./includes/

INCLD			=	${INCLD_DIR}pipex.h

# **************************************************************************** #
#                                                                              #
#                                  RULES                                       #
#                                                                              #
# **************************************************************************** #

all:  ${NAME}

${LIB_PATH}: ${LIB_SOURCES} ${LIB_INCLD}
	@echo "Compilation - Libft\n"
	@make -C ${LIBFT_FOLDER} --no-print-directory
	@echo "${COLOUR_GREEN}Libft compiled\n${COLOUR_END}"

${NAME}: ${OBJECTS} ${LIB_PATH} ${INCLD}
	@echo "Compilation - Pipex\n"
	@${CC} ${CFLAGS} ${OBJECTS} ${LIB_PATH} -o ${NAME}
	@echo "${COLOUR_GREEN}Pipex compiled\n${COLOUR_END}"

${OBJECTS_PATH}%.o:	${SOURCES_PATH}%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@make fclean -C libft/ --no-print-directory
	@rm -rf ${OBJECTS_PATH}

fclean:
	@make fclean -C libft/ --no-print-directory
	@rm -rf ${OBJECTS_PATH}
	@rm -f ${NAME}  
	@echo "${COLOUR_GREEN}Pipex cleaned\n${COLOUR_END}"

re: fclean all

.PHONY: fclean clean all re