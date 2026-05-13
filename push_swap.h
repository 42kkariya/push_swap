/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:07:25 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/13 15:19:29 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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
