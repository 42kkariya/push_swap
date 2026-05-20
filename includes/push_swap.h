/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:07:25 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/18 17:15:10 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define ERROR 1
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_flag
{
	int	sim;
	int	med;
	int	com;
	int	ada;
	int	ben;
	int	check;
}	t_frag;

typedef struct s_counts
{
	int	cnt_sa;
	int	cnt_sb;
	int	cnt_ss;
	int	cnt_pa;
	int	cnt_pb;
	int	cnt_ra;
	int	cnt_rb;
	int	cnt_rr;
	int	cnt_rra;
	int	cnt_rrb;
	int	cnt_rrr;
}	t_counts;

typedef struct s_stacks
{
	t_list		**a;
	t_list		**b;
	t_counts	*cnt;
}	t_stacks;

// frag

void	ft_check_frag(char *argv, t_frag *frag, t_list **cy_list);
int		ft_strcmp(char *dest, char *src);
void	ft_frag_nbr_check(t_frag *frag, t_list **cy_list);
void	zerofrag(t_frag *frag);
void	zerocount(t_counts *counts);
void	print_bench(t_frag *frag, t_counts *counts, double disorder);

// list

void	ft_join_list(t_list **cy_list);
t_list	*ft_listlast(t_list *cy_list);
t_list	*ft_listnew(int nb, t_list **cy_list);
void	ft_make_cy_list(t_list **cy_list, t_frag *frag, int argc, char **argv);
void	ft_list_add_back(t_list **cy_list, t_list *node);

// src

void	ft_argv_check(int argc, char **argv, t_list **cy_list);
void	ft_nbrcheck(int *map, int j);
int		ft_check(int nb, int *map, int size);
int		ft_atoi(char *nb, t_list **cy_list);
void	ft_exit(int error, t_list *cy_list);

// printf

int		ft_printf(int fd, const char *format, ...);
int		ft_print_char(int c, int fd);
int		ft_print_str(char *s, int fd);
int		ft_print_nbr(int n, int fd);
int		ft_print_unsigned(unsigned int n, int fd);
int		ft_print_hex(unsigned int n, char spec, int fd);
int		ft_print_ptr(void *ptr, int fd);
int		ft_print_nbr_base(unsigned long n, char *base, int fd);
int		ft_print_double(double n, int fd);

/* oparation */
void	sa(t_list **stack_a, t_counts *counts);
void	sb(t_list **stack_b, t_counts *counts);
void	ss(t_list **stack_a, t_list **stack_b, t_counts *counts);
void	pa(t_list **stack_a, t_list **stack_b, t_counts *counts);
void	pb(t_list **stack_a, t_list **stack_b, t_counts *counts);
void	ra(t_list **stack_a, t_counts *counts);
void	rb(t_list **stack_b, t_counts *counts);
void	rr(t_list **stack_a, t_list **stack_b, t_counts *counts);
void	rra(t_list **stack_a, t_counts *counts);
void	rrb(t_list **stack_b, t_counts *counts);
void	rrr(t_list **stack_a, t_list **stack_b, t_counts *counts);

/* sort */
void	sort_simple(t_list **stack_a, t_list **stack_b, t_counts *counts);
void	sort_radix(t_list **stack_a, t_list **stack_b, t_counts *counts);
void	sort_turk(t_list **stack_a, t_list **stack_b, t_counts *counts);
void	sort_dispatch(t_list **sa, t_list **sb, t_frag *frag, t_counts *cnt);
double	calc_disorder(t_list *stack);

/* sort utils */
int		stack_size(t_list *stack);
int		get_rank(t_list *head, t_list *node);
void	do_move(t_stacks *st, t_list *best, t_list *target);

#endif
