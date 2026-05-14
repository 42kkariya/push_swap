/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:07:25 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/14 17:32:39 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define ERROR 1
# define INT_RANGE_SIZE 4294967296

// frag

t_frag	*ft_check_frag(t_frag *frag, char *str);
size_t	sim_check(char *str, char *sim);
size_t	med_check(char *str, char *med);
size_t	com_check(char *str, char *com);
size_t	ada_check(char *str, char *ada);

// list

void	ft_join_list(a_list **cy_list);
a_list	*ft_listlast(a_list *cy_list);
a_list	*ft_listnew(int nb);
int		ft_make_cy_list(a_list	**cy_list, t_frag *frag, int argc, char **argv);
void	ft_list_add_back(a_list ***cy_list, a_list	*new);

// src

void	ft_argc_check(int argc, char **argv);
int		ft_atoi(char *nb);
void	ft_exit(int error);



typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
	struct s_list	*prev;
} a_list;

typedef struct s_flag
{
	int	sim;
	int	med;
	int	com;
	int	ada;
} t_frag;

#endif
