NAME = push_swap

SRC = src/main.c\
	src/ft_split.c\
	src/ft_strlcpy.c\
	src/ft_strlen.c\
	src/swap.c src/push.c src/rotate.c src/reverse_rotate.c\
	src/index.c src/utils.c\
	src/position.c\
	src/move_rotate.c\
	src/cost.c src/algorithm.c src/is_sorted.c\
	src/check_utils.c src/node_utils.c\
	
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

INCLUDES = -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re