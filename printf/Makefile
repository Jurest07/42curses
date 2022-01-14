# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slight <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 16:14:58 by slight            #+#    #+#              #
#    Updated: 2022/01/14 19:19:23 by slight           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEAD = ft_printf.h

LIST_A = ft_printf.c print_digit.c print_chars.c print_functions2.c str_fun.c

OBJ = $(patsubst %.c,%.o,$(LIST_A))

FLAGS = -Wall -Werror -Wextra

M = Makefile

all: $(NAME) 

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

$(OBJ): $(HEAD) $(M) 

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

bonus: 
	@make OBJ="$(OBJ_B)" all

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
