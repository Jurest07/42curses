# constants
NAME	=	libft.a

bin   	=	$(NAME)
cflags	=	-c -Wall -Wextra -Werror
trgdir	=	trg

srcs  	=	ft_atoi.c        ft_bzero.c        ft_calloc.c     ft_isalnum.c    \
			ft_isalpha.c     ft_isascii.c      ft_isdigit.c    ft_isprint.c    \
			ft_itoa.c        ft_memchr.c       ft_memcmp.c     ft_memcpy.c     \
			ft_memmove.c     ft_memset.c       ft_putchar_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c   ft_putstr_fd.c    ft_split.c      ft_strchr.c     \
			ft_strdup.c      ft_striteri.c     ft_strjoin.c    ft_strlcat.c    \
			ft_strlcpy.c     ft_strlen.c       ft_strmapi.c    ft_strncmp.c    \
			ft_strnstr.c     ft_strrchr.c      ft_strtrim.c    ft_substr.c     \
			ft_tolower.c     ft_toupper.c

bsrcs 	=	ft_lstnew.c      ft_lstadd_front.c ft_lstsize.c    ft_lstlast.c    \
			ft_lstadd_back.c ft_lstdelone.c    ft_lstclear.c   ft_lstiter.c    \
			ft_lstmap.c



# calculated
objs  := $(patsubst  %.c,%.o,$(srcs))
objs  := $(addprefix $(trgdir)/,$(objs))
dfls  := $(patsubst  %.o,%.d,$(objs))

bobjs := $(patsubst  %.c,%.o,$(bsrcs))
bobjs := $(addprefix $(trgdir)/,$(bobjs))
bdfls := $(patsubst  %.o,%.d,$(bobjs))



# common
all: build

build: $(bin)

bonus: add_bonus

re: fclean build

clean:
	rm -rf $(trgdir)

fclean: clean
	rm -f $(bin)

.PHONY: all build bonus add_bonus re clean fclean



# compilation and linking
$(bin): $(objs)
	ar -r $(bin) $?

$(trgdir)/%.o: %.c
	@mkdir -p $(dir $@)
	gcc -o $@ $(cflags) -MD $<

add_bonus: $(bobjs)
	@make objs="$(bobjs)"

include $(wildcard $(dfls))
include $(wildcard $(bdfls))

so:
	$(CC) -nostartfiles -fPIC $(cflags) $(srcs) $(bsrcs)
	gcc -nostartfiles -shared -o libft.so $(objs) $(bobjs)



# END
