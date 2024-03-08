NAME := so_long
CC := gcc
FLAGS := -Wall -Wextra -Werror -g3

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
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\033[1;32mCompiling $(NAME)...\033[0m"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit
	@echo "\033[1;32m$(NAME) created ✔️\033[0m"

all: $(NAME)

clean:
	@$(RM) *.o */*.o */*/*.o
	@rm -rf $(NAME).dSYM
	@echo "\033[1;31mDeleting $(NAME) objs ✔️\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;31mDeleting $(NAME) binary ✔️\033[0m"

re: fclean all

.PHONY: all clean fclean re
