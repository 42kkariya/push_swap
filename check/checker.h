/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:43:47 by mtaisei           #+#    #+#             */
/*   Updated: 2026/06/01 13:46:14 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define FALSE 0
# define TRUE 1
# define ERROR 1
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_gnl
{
	char	*buf;
	char	*res;
	char	*line;
}	t_gnl;

typedef struct s_flag
{
	int	sim;
	int	med;
	int	com;
	int	ada;
	int	ben;
	int	check;
}	t_frag;

// get_next_line
char	*checker_get_next_line(int fd);
char	*checker_free_save_all(t_gnl gnl, char **save);
int		checker_updeta_save(t_gnl *gnl, char **save);
int		checker_read_and_save(int fd, t_gnl *gnl);
int		checker_my_get_line(t_gnl *gnl);

// get_next_line_bonus
char	*checker_ft_strchr(char *str, char c);
char	*checker_gnl_free_all(t_gnl gnl);
int		checker_ft_strjoin_free(t_gnl *gnl);
int		checker_ft_strlen(char *str);
char	*checker_ft_strdup(char *src);

// operations
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

// checker utils
void	checker_free_all(int new_argc, char **new_argv, t_list *a_stack);
int		checker_strcmp(char *src, char *dest);
int		is_sorted(t_list *a_stack);
int		empty(t_list *b_stack);
int		ft_checker(t_list **a_stack);
void	check_stack(t_list *a_stack, t_list *b_stack);
void	checker_swap(char *line, t_list **a_stack, t_list **b_stack);
int		linecheck(char *line);
int		free_b_stack(t_list *b_stack);
int		ft_fragcheck(t_list *a_stack, t_frag frag,
			char **new_argv, int new_argc);

// shared push_swap utils
void	ft_check_frag(char *argv, t_frag *frag);
void	zerofrag(t_frag *frag);
int		ft_strcmp(char *dest, char *src);
void	ft_argv_check(int argc, char **argv, t_list **cy_list);
void	ft_nbrcheck(int *map, int j, int argc, char **argv);
int		ft_check(int nb, int *map, int size);
int		ft_atoi(char *nb, t_list **cy_list);
void	ft_argv_error(int argc, char **argv, int *map);
int		ft_fill_map(int argc, char **argv, int *map);
void	ft_exit(int error, t_list *cy_list);
void	ft_join_list(t_list **cy_list);
t_list	*ft_listlast(t_list *cy_list);
t_list	*ft_listnew(int nb, t_list **cy_list);
void	ft_make_cy_list(t_list **cy_list, t_frag *frag, int argc, char **argv);
void	ft_list_add_back(t_list **cy_list, t_list	*new);
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
int		ft_printf(int fd, const char *format, ...);
int		ft_print_char(int c, int fd);
int		ft_print_str(char *s, int fd);
int		ft_print_nbr(int n, int fd);
int		ft_print_unsigned(unsigned int n, int fd);
int		ft_print_hex(unsigned int n, char spec, int fd);
int		ft_print_ptr(void *ptr, int fd);
int		ft_print_nbr_base(unsigned long n, char *base, int fd);

#endif
