NAME = libftprintf.a

makefile := Makefile
srcdirs  := .
cflags   := -c -Wall -Wextra -Werror
trgdir   := trg
libftdir := ./libft
libft    := $(libftdir)/libft.a

srcs := ./calculate_width.c ./parse_place.c   ./printf.c      \
        ./print_filler.c    ./print_integer.c ./print_place.c \
        ./utils.c
objs := $(patsubst %.c,%.o,$(srcs))
objs := $(patsubst ./%,$(trgdir)/%,$(objs))
dirs := $(dir $(objs))




# common
all: build

bonus: all

build: $(NAME)

re: fclean build

clean:
	rm -rf $(trgdir)
	make -C ./libft fclean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

.PHONY: all bonus build re clean fclean



# compilation and linking
$(NAME): $(objs) $(libft)
	-cp -n $(libft) $(NAME)
	ar -r $@ $(objs)

$(trgdir)/%.o: %.c $(makefile)
	@mkdir -p "$(dir $@)"
	gcc -o $@ $(cflags) -MD $<

$(libft):
	@make -C $(libftdir)

include $(shell if [ -d $(trgdir) ]; then find $(trgdir) -name "*.d"; fi)



# END
