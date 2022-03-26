NAME = so_long

HEAD = headers/

TEST_MAP = maps/map.ber

SRC = src/die.c src/draw.c src/init_game.c src/init_map.c src/init_map2.c \
		src/init_structs.c src/keys_press.c src/so_long.c src/destroed.c	

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -L/usr/include/../lib -lXext -lX11 -lm -lbsd -lz

all: $(NAME)

%.o: %.c $(HEAD)/*
	@ $(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ) $(HEAD)/*
	$(CC) $(OBJ) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@ echo "so_long was compiled"

bonus: all

clean:
	@ rm -f $(OBJ)
	@ echo ".o fails was deleted"

fclean: clean
	@ rm -f $(NAME)
	@ echo "fclean was comtlited"

re: fclean all

run: all
	./$(NAME) $(TEST_MAP)

.PHONY: all clean fclean re bonus run