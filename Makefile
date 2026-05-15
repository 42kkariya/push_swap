# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/15 18:42:56 by mtaisei           #+#    #+#              #
#    Updated: 2026/05/15 19:04:14 by mtaisei          ###   ########.fr        #
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
		printf/ft_printf.c\
		printf/print/ft_putnbr_unsigned_base.c\
		printf/print/ft_putnbr_signed.c\
		printf/print/c_print.c\
		printf/print/d_print.c\
		printf/print/i_print.c\
		printf/print/p_print.c\
		printf/print/s_print.c\
		printf/print/u_print.c\
		printf/print/x_print.c\
		printf/print/up_x_print.c

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
