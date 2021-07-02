# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 16:42:39 by cabouelw          #+#    #+#              #
#    Updated: 2021/07/02 17:06:33 by cabouelw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_C = checker
LIB_PATH = Libft
LIB = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_P =	push_swap.c\
		swap/swap.c\
		swap/case_swap.c\
		swap/ft_tools.c\
		swap/case_more.c\
		swap/ft_tab.c\
		swap/ft_sort_stack.c\

SRC_C =	ft_checker/ft_checker.c\
		ft_checker/ft_tools.c\
		ft_checker/parsing.c\
		ft_checker/swap_bonus.c\

OBJ_P = $(SRC_P:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_P) $(LIB)
	@gcc $(OBJ_P) $(LIB_PATH)/$(LIB) -o $(NAME)

bonus: $(OBJ_C) $(LIB)
	@gcc $(OBJ_C) $(LIB_PATH)/$(LIB) -o $(NAME_C)

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@make clean -C $(LIB_PATH)/
	@rm -rf $(OBJ_P) $(OBJ_C)

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -rf $(NAME) $(NAME_C)

re: fclean all
