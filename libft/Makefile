# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slight <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 16:14:58 by slight            #+#    #+#              #
#    Updated: 2021/10/19 13:46:04 by slight           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEAD = libft.h

LIST_A =	ft_atoi.c		ft_bzero.c		ft_calloc.c\
			ft_isalnum.c	ft_isalpha.c	ft_isascii.c\
			ft_isdigit.c	ft_isprint.c	ft_itoa.c\
			ft_memchr.c		ft_memcmp.c		ft_memcpy.c\
			ft_memmove.c	ft_memset.c		ft_putchar_fd.c\
			ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c\
			ft_split.c		ft_strchr.c		ft_strdup.c\
			ft_striteri.c	ft_strjoin.c	ft_strlcat.c\
			ft_strlcpy.c	ft_strlen.c		ft_strmapi.c\
			ft_strncmp.c	ft_strnstr.c	ft_strrchr.c\
			ft_strtrim.c	ft_substr.c		ft_tolower.c\
			ft_toupper.c

LIST_B =	ft_lstadd_back_bonus.c	ft_lstadd_front_bonus.c\
			ft_lstclear_bonus.c	ft_lstdelone_bonus.c		ft_lstmap_bonus.c\
			ft_lstiter_bonus.c	ft_lstlast_bonus.c		ft_lstnew_bonus.c\
			ft_lstsize_bonus.c


OBJ = $(patsubst %.c,%.o,$(LIST_A))
OBJ_B = $(patsubst %.c,%.o,$(LIST_B))

D_FILES = $(patsubst %.c,%.d,$(LIST_A) $(LIST_B))

FLAGS = -Wall -Werror -Wextra

M = Makefile

all: $(NAME) 

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

$(OBJ): $(HEAD) $(M) 

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

bonus: 
	@make OBJ="$(OBJ_B)" all

clean:
	@rm -f $(OBJ) $(OBJ_B) $(D_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
