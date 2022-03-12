NAME = push_swap

NAME_BONUS = checker

CC = gcc

HEADLID = headers/

SRC = check_inputs.c errors.c list_functions.c push_and_rotate_instructions.c \
	  push_swap.c reverse_rotate_instructions.c swaps_instruction.c init_structs.c skip_functions.c \
	  check_on_ints.c check_max_and_min.c sort.c sup_fun.c find_max_sort.c do_operations.c \
	  find_min_iters.c find_scores.c clounada.c

SRC_BONUS = check_inputs.c errors.c list_functions.c push_and_rotate_instructions.c \
	  checker.c reverse_rotate_instructions.c swaps_instruction.c init_structs.c skip_functions.c \
	  check_on_ints.c check_max_and_min.c sort.c sup_fun.c find_max_sort.c do_operations.c \
	  find_min_iters.c find_scores.c clounada.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME) 

bonus: $(NAME_BONUS)

libft/libft.a :
	make -C libft

%.o: %.c
	$(CC) $(FLAGS) -I$(HEADLID) -c $< -o $@

$(NAME): $(OBJ) libft/libft.a
	$(CC) $(OBJ) libft/libft.a -o $(NAME)

$(NAME_BONUS) : $(OBJ_BONUS) libft/libft.a
	$(CC) $(OBJ_BONUS) libft/libft.a -o $(NAME_BONUS)

clean:
	@rm -f $(OBJ) 
	@rm -f $(OBJ_BONUS)
	make -C libft fclean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re: fclean all bonus

run: all
	./$(NAME)

run_bonus: bonus
	./$(NAME_BONUS)

.PHONY: all clean fclean re bonus run