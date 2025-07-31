NAME = libftprintf.a
SRCS = ft_printf.c ft_print_put.c ft_print_ptr.c ft_print_unsigned.c\
	ft_puthex.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS =  -Wall -Werror -Wextra
RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY : all clean fclean re