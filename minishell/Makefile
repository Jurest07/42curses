NAME = minishell

CC = gcc

HEADDIR = headers/

SRC = src/main.c src/utils.c src/lexer.c src/list_functions.c src/lexer_functions.c src/lexer_function2.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c $(HEADDIR)/*
	$(CC) $(FLAGS) -I$(HEADDIR) -c $< -o $@ 

$(NAME): $(OBJ) $(HEADLID)/*
	$(CC) $(OBJ) -lreadline -o $(NAME)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)


.PHONY: all clean fclean re run