/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:32:26 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/14 17:32:26 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_list	*search_min(t_list *stack)
{
	t_list	*result;
	t_list	*first;

	first = (stack);
	result = (stack);
	while ((stack)->next != first)
	{
		if ((stack)->nbr < (result->nbr))
			result = (stack);
		stack = (stack)->next;
	}
	if ((stack)->nbr < (result->nbr))
		result = (stack);
	return (result);
}

static void	rotate_list(t_list **stack, t_counts *counts)
{
	t_list	*min_value;

	min_value = search_min(*stack);
	while ((*stack)->nbr != min_value->nbr)
	{
		ra(stack, counts);
	}
}

static void	push_stack_b(t_list **stack_a, t_list **stack_b, t_counts *counts)
{
	while (*stack_a)
	{
		rotate_list(stack_a, counts);
		pb(stack_a, stack_b, counts);
	}
	while (*stack_b)
	{
		pa(stack_a, stack_b, counts);
	}
}

void	sort_simple(t_list **stack_a, t_list **stack_b, t_counts *counts)
{
	push_stack_b(stack_a, stack_b, counts);
}
