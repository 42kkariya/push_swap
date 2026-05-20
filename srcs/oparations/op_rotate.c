/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 14:27:56 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/14 14:27:56 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_list **stack)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	ra(t_list **stack_a, t_counts *counts)
{
	rotate(stack_a);
	counts->cnt_ra++;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, t_counts *counts)
{
	rotate(stack_b);
	counts->cnt_rb++;
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, t_counts *counts)
{
	rotate(stack_a);
	rotate(stack_b);
	counts->cnt_rr++;
	write(1, "rr\n", 3);
}
