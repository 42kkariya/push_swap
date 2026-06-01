# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/15 18:42:56 by mtaisei           #+#    #+#              #
#    Updated: 2026/05/29 17:08:27 by mtaisei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -fr

SRCS =	main.c\
		srcs/frag/ft_frag.c\
		srcs/frag/bench.c\
		srcs/list/ft_list.c\
		srcs/utils/ft_argv_check.c\
		srcs/utils/ft_argv_check_utils.c\
		srcs/utils/ft_utils.c\
		srcs/printf/ft_printf.c\
		srcs/printf/ft_print_nbr_base.c\
		srcs/printf/ft_print_numbers.c\
		srcs/sort/sort_simple.c\
		srcs/sort/sort_radix.c\
		srcs/sort/sort_turk.c\
		srcs/sort/sort_turk_move.c\
		srcs/sort/sort_turk_utils.c\
		srcs/sort/sort_chunk.c\
		srcs/sort/sort_dispatch.c\
		srcs/operations/op_push.c\
		srcs/operations/op_swap.c\
		srcs/operations/op_rotate.c\
		srcs/operations/op_reverse_rotate.c\
		srcs/argv/make_new_argv.c\
		srcs/argv/ft_split.c
		
SRCSBONUS = check/check_main.c\
			check/GNL/get_next_line_utils.c\
			check/GNL/get_next_line.c\
			check/operations/check_push.c\
			check/operations/check_rev_rot.c\
			check/operations/check_rot.c\
			check/operations/check_swap.c\
			check/utils/checker_utils.c\
			check/utils/checker.c\
			srcs/frag/ft_frag.c\
			srcs/list/ft_list.c\
			srcs/utils/ft_argv_check.c\
			srcs/utils/ft_argv_check_utils.c\
			srcs/utils/ft_utils.c\
			srcs/printf/ft_printf.c\
			srcs/printf/ft_print_nbr_base.c\
			srcs/printf/ft_print_numbers.c\
			srcs/argv/make_new_argv.c\
			srcs/argv/ft_split.c\
			

OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(SRCSBONUS:.c=.o)

all: $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS) : $(OBJSBONUS)
	$(CC) $(CFLAGS) $(OBJSBONUS) -Wl,-dead_strip -o $(BONUS)

%.o : %.c includes/push_swap.h check/checker.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJSBONUS)
fclean: clean
	$(RM) $(NAME) $(BONUS)

re:	fclean all

.PHONY: all bonus clean fclean re
