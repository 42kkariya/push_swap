# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/15 18:42:56 by mtaisei           #+#    #+#              #
#    Updated: 2026/05/21 11:12:00 by mtaisei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -fr

SRCS =	main.c\
		srcs/frag/ft_check_frag.c\
		srcs/frag/zerofrag.c\
		srcs/frag/bench.c\
		srcs/list/ft_join_list.c\
		srcs/list/ft_listlast.c\
		srcs/list/ft_listnew.c\
		srcs/list/ft_make_cy_list.c\
		srcs/list/list_add_back.c\
		srcs/utils/ft_argv_check.c\
		srcs/utils/ft_atoi.c\
		srcs/utils/ft_exit.c\
		srcs/printf/ft_printf.c\
		srcs/printf/ft_print_char.c\
		srcs/printf/ft_print_str.c\
		srcs/printf/ft_print_nbr_base.c\
		srcs/printf/ft_print_numbers.c\
		srcs/sort/sort_simple.c\
		srcs/sort/sort_radix.c\
		srcs/sort/sort_turk.c\
		srcs/sort/sort_turk_move.c\
		srcs/sort/sort_dispatch.c\
		srcs/sort/sort_check.c\
		srcs/operations/op_push.c\
		srcs/operations/op_swap.c\
		srcs/operations/op_rotate.c\
		srcs/operations/op_reverse_rotate.c\
		make_new_argv/make_new_argv.c\
		make_new_argv/ft_split.c\
		make_new_argv/ft_one_line.c\
		make_new_argv/ft_argv_exit.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c includes/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
