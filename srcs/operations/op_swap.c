/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 14:27:21 by kkariya           #+#    #+#             */
/*   Updated: 2026/06/01 13:52:40 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_list **stack)
{
	int	tmp;

	if (!*stack || (*stack)->next == *stack)
		return ;
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
}

void	sa(t_list **stack_a, t_counts *counts)
{
	swap(stack_a);
	counts->cnt_sa++;
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, t_counts *counts)
{
	swap(stack_b);
	counts->cnt_sb++;
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, t_counts *counts)
{
	swap(stack_a);
	swap(stack_b);
	counts->cnt_ss++;
	write(1, "ss\n", 3);
}
