# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/15 18:42:56 by mtaisei           #+#    #+#              #
#    Updated: 2026/05/16 22:18:16 by mtaisei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Iprintf
RM = rm -fr

SRCS =	main.c\
		frag/ft_check_frag.c\
		frag/zerofrag.c\
		list/ft_join_list.c\
		list/ft_listlast.c\
		list/ft_listnew.c\
		list/ft_make_cy_list.c\
		list/list_add_back.c\
		src/ft_argv_check.c\
		src/ft_atoi.c\
		src/ft_exit.c\
		srcs/printf/ft_printf.c \
		srcs/printf/ft_print_char.c \
		srcs/printf/ft_print_str.c \
		srcs/printf/ft_print_nbr_base.c \
		srcs/printf/ft_print_numbers.c\
		make_new_argv/make_new_argv.c\
		make_new_argv/ft_split.c\
		make_new_argv/ft_one_line.c\
		make_new_argv/ft_argv_exit.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
