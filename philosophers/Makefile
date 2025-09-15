# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 17:00:13 by juan-jof          #+#    #+#              #
#    Updated: 2025/07/01 17:31:20 by juan-jof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread
RM = rm -f

INCDIR = includes

SRCS = srcs/main.c \
	srcs/parsing.c \
	srcs/utils.c \
	srcs/init.c \
	srcs/cleanup.c \
	srcs/timing.c \
	srcs/logs.c \
	srcs/simulation.c \
	srcs/forks.c \
	srcs/monitor.c \
	srcs/threads.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re



		