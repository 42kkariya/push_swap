/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 14:27:45 by kkariya           #+#    #+#             */
/*   Updated: 2026/06/01 13:52:37 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}

void	rra(t_list **stack_a, t_counts *counts)
{
	reverse_rotate(stack_a);
	counts->cnt_rra++;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, t_counts *counts)
{
	reverse_rotate(stack_b);
	counts->cnt_rrb++;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, t_counts *counts)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	counts->cnt_rrr++;
	write(1, "rrr\n", 4);
}
