/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 15:35:00 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/23 15:35:00 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	turk_sort_three(t_list **stack_a, t_counts *counts)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(*stack_a))
		return ;
	first = (*stack_a)->nbr;
	second = (*stack_a)->next->nbr;
	third = (*stack_a)->prev->nbr;
	if (first > second && first > third)
		ra(stack_a, counts);
	else if (second > first && second > third)
		rra(stack_a, counts);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a, counts);
}

void	turk_push_to_b(t_stacks *st, int size)
{
	int	remaining;
	int	median;

	remaining = size;
	median = size / 2;
	while (remaining > 3)
	{
		pb(st->a, st->b, st->cnt);
		if ((*st->b)->nbr < median && (*st->b)->next != *st->b)
			rb(st->b, st->cnt);
		remaining--;
	}
}

int	turk_prepare(t_list **stack_a, t_counts *counts, int size)
{
	int	*arr;

	if (size <= 1)
		return (0);
	if (size == 2)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			sa(stack_a, counts);
		return (0);
	}
	arr = to_index(*stack_a, size);
	if (!arr)
		return (0);
	free(arr);
	if (size == 3)
	{
		turk_sort_three(stack_a, counts);
		return (0);
	}
	return (1);
}
