NAME = so_long

HEADLID = heders/

TEST_MAP = maps/map.ber

SRC = die.c draw.c init_game.c init_map.c init_map2.c init_structs.c \
	  keys_press.c so_long.c destroed.c	

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra -L/usr/include/../lib -lXext -lX11 -lm -lbsd -lz

all: $(NAME)

%.o: %.c
	@ $(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
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