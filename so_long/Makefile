NAME = so_long

HEADLID = heders/

LIBS = libmlx.a 

SRC = die.c draw.c init_game.c init_map.c init_map2.c init_structs.c \
	  keys_press.c mlx_utils.c so_long.c destroed.c	

OBJ = $(SRC:.c=.o)

FLAGSX = -L/usr/include/../lib -lXext -lX11 -lm -lbsd

FLAGSALL = -Wall -Werror -Wextra -L/usr/include/../lib -lXext -lX11 -lm -lbsd

all: $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

#.c.o:
#	gcc $(FLAGSX) -I$(HEADLIB) $< -o $@

bonus: 
	@make OBJ="$(OBJ_B)" all

clean:
	@rm -f $(OBJ) $(OBJ_B) $(D_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re bonus run