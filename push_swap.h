/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:07:25 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/15 14:41:25 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define ERROR 1
# define INT_MIN -2147483648
# define INT_MAX 2147483647

// frag

void	ft_check_frag(char	*argv, t_frag *frag, t_alist **cy_list);
int		ft_free_strcmp(char *dest, char *src, t_alist **cy_list);
void	ft_frag_nbr_check(t_frag *frag, t_alist **cy_list);

// list

void	ft_join_list(t_alist **cy_list);
t_alist	*ft_listlast(t_alist *cy_list);
t_alist	*ft_listnew(int nb, t_alist **cy_list);
void	ft_make_cy_list(t_alist	**cy_list, t_frag *frag, int argc, char **argv);
void	ft_list_add_back(t_alist **cy_list, t_alist	*new);

// src

void	ft_argv_check(int argc, char **argv, t_alist **cy_list);
int		ft_atoi(char *nb, t_alist **cy_list);
void	ft_exit(int error, t_alist *cy_list);

typedef struct _list
{
	int				nbr;
	struct s_list	*next;
	struct s_list	*prev;
}	t_alist;

typedef struct s_flag
{
	int	sim;
	int	med;
	int	com;
	int	ada;
	int	ben;
	int	check;
}	t_frag;

#endif
