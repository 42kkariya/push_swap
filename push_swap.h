/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:07:25 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/16 22:17:44 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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

# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_str(char *s);
int		ft_print_nbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, char spec);
int		ft_print_ptr(void *ptr);
int		ft_print_nbr_base(unsigned long n, char *base);

// make_new_argv

char	**make_new_argv(int argc, char **argv, int *wordcount);
char	**ft_split(char *str, int *wordcount);
char	*ft_one_line(int argc, char **argv);
char	*ft_strjoin_free(char *dest, char *src);
int		ft_strlen(char *str);
void	ft_argv_exit(char *str);
char	*ft_cpy(char *split, char *src);
void	ft_free_split(char *str, char **split, int j);
int		ft_wordlen(char *str);
int		ft_word_count(char *str, int *wordcount);

#endif
