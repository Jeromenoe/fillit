# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 10:43:07 by trlevequ          #+#    #+#              #
#    Updated: 2018/11/28 12:21:30 by trlevequ         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_PATH	=	includes/

SRC_PATH	=	srcs/

SRC_NAME 	=	ft_fillit.c		\
				ft_makelist.c	\
				ft_check_file.c	\
				ft_allocate.c	\
				ft_print.c

OBJ_PATH	=	objs/

CPPFLAGS	=	-Iinclude

LDFLAGS		=	-Llibft
LDLIBS		=	-lft
LIB			=	fillit.h

NAME		=	fillit

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

OBJ_NAME	=	$(SRC_NAME:.c=.o)

SRC			=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@ -Iincludes

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $< -Iincludes

lib_make_fclean:
	make -C libft/ fclean

lib_make_clean:
	make -C libft/ clean

clean: lib_make_clean
	rm -rf $(OBJ_PATH)

fclean: clean lib_make_fclean
	rm -rf $(NAME)

re: lib_make_fclean fclean all

.PHONY:	all, clean, fclean, re
