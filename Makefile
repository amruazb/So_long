NAME := so_long
CC := gcc
FLAGS := -Wall -Wextra -Werror -g3
UNAME := $(shell uname)

SRCS := controls.c \
        exitfree.c \
        ft_printf.c \
        ft_trim.c \
        get_next_line.c \
        graphicsadd.c \
        map_utilities3.c \
        maputilities.c \
        maputilities2.c \
        so_long.c \
        utils.c

OBJS := $(SRCS:.c=.o)

.c.o:
ifeq ($<, map_utilities3.c)
	$(CC) $(FLAGS) -c $< -o $@
else
	$(CC) $(FLAGS) -Wno-error -c $< -o $@
endif


$(NAME): $(OBJS)
ifeq ($(UNAME), Darwin)
	echo "\033[1;32mCompiling $(NAME) for macOS...\033[0m"
	$(MAKE) -C mlx all
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit
	echo "\033[1;32m$(NAME) created ✔️\033[0m"
else
	echo "\033[1;32mCompiling $(NAME) for Linux...\033[0m"
	$(MAKE) -C mlx_linux all
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
	echo "\033[1;32m$(NAME) created ✔️\033[0m"
endif

all: $(NAME)

clean:
	$(RM) *.o */*.o */*/*.o
	rm -rf $(NAME).dSYM
	echo "\033[1;31mDeleting $(NAME) objs ✔️\033[0m"
	$(MAKE) -C mlx clean 2>/dev/null || true
	$(MAKE) -C mlx_linux clean 2>/dev/null || true

fclean: clean
	$(RM) $(NAME)
	echo "\033[1;31mDeleting $(NAME) binary ✔️\033[0m"

re: fclean all

.PHONY: all clean fclean re
