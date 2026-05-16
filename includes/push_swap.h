/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:07:25 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/16 13:23:21 by mtaisei          ###   ########.fr       */
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

// frag

void	ft_check_frag(char	*argv, t_frag *frag, t_list **cy_list);
int		ft_strcmp(char *dest, char *src);
void	ft_frag_nbr_check(t_frag *frag, t_list **cy_list);
void	zerofrag(t_frag *frag);

// list

void	ft_join_list(t_list **cy_list);
t_list	*ft_listlast(t_list *cy_list);
t_list	*ft_listnew(int nb, t_list **cy_list);
void	ft_make_cy_list(t_list	**cy_list, t_frag *frag, int argc, char **argv);
void	ft_list_add_back(t_list **cy_list, t_list	*new);

// src

void	ft_argv_check(int argc, char **argv, t_list **cy_list);
void	ft_nbrcheck(int *map, int j);
int		ft_check(int nb, int *map, int size);
int		ft_atoi(char *nb, t_list **cy_list);
void	ft_exit(int error, t_list *cy_list);

// printf

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_str(char *s);
int		ft_print_nbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, char spec);
int		ft_print_ptr(void *ptr);
int		ft_print_nbr_base(unsigned long n, char *base);

/* oparation */
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/* sort */
void	sort_simple(t_list **stack_a, t_list **stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b);

#endif
