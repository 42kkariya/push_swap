/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:00:59 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/21 17:05:20 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_list	*find_target(t_list *stack_a, int nbr)
{
	t_list	*min_node;
	t_list	*head;

	head = stack_a;
	min_node = head;
	stack_a = head->next;
	while (stack_a != head)
	{
		if (min_node->nbr > stack_a->nbr)
			min_node = stack_a;
		stack_a = stack_a->next;
	}
	if (head->nbr < nbr && nbr < head->next->nbr)
		return (head->next);
	stack_a = head->next;
	while (stack_a != head)
	{
		if ((stack_a->nbr) < nbr && nbr < (stack_a->next->nbr))
			return (stack_a->next);
		stack_a = stack_a->next;
	}
	return (min_node);
}

static int	calc_cost(t_list *stack_a, t_list *stack_b, t_list *node)
{
	t_list	*target;
	int		rank_a;
	int		rank_b;
	int		cost_a;
	int		cost_b;

	target = find_target(stack_a, node->nbr);
	rank_a = get_rank(stack_a, target);
	rank_b = get_rank(stack_b, node);
	if (rank_a * 2 <= stack_size(stack_a))
		cost_a = rank_a;
	else
		cost_a = stack_size(stack_a) - rank_a;
	if (rank_b * 2 <= stack_size(stack_b))
		cost_b = rank_b;
	else
		cost_b = stack_size(stack_b) - rank_b;
	if ((cost_a == rank_a) == (cost_b == rank_b))
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

static t_list	*best_node(t_list *stack_a, t_list *stack_b)
{
	t_list	*head;
	t_list	*result;
	int		min_cost;
	int		temp;

	head = stack_b;
	result = stack_b;
	min_cost = calc_cost(stack_a, head, stack_b);
	stack_b = stack_b->next;
	while (stack_b != head)
	{
		temp = calc_cost(stack_a, head, stack_b);
		if (min_cost > temp)
		{
			result = stack_b;
			min_cost = temp;
		}
		stack_b = stack_b->next;
	}
	return (result);
}

void	rotate_to_min(t_list **stack_a, t_counts *counts)
{
	t_list	*head;
	t_list	*curr;
	t_list	*min_node;
	int		rank;
	int		sz;

	head = *stack_a;
	curr = (*stack_a)->next;
	min_node = *stack_a;
	while (curr != head)
	{
		if (min_node->nbr > curr->nbr)
			min_node = curr;
		curr = curr->next;
	}
	rank = get_rank(head, min_node);
	sz = stack_size(*stack_a);
	if (rank <= (sz / 2))
		while (rank-- > 0)
			ra(stack_a, counts);
	else
		while (sz-- > rank)
			rra(stack_a, counts);
}

void	sort_turk(t_list **stack_a, t_list **stack_b, t_counts *counts)
{
	t_list		*best;
	t_list		*target;
	t_stacks	st;

	if (stack_size(*stack_a) <= 1)
		return ;
	st.a = stack_a;
	st.b = stack_b;
	st.cnt = counts;
	while (*stack_a)
		pb(stack_a, stack_b, counts);
	pa(stack_a, stack_b, counts);
	while (*stack_b)
	{
		best = best_node(*stack_a, *stack_b);
		target = find_target(*stack_a, best->nbr);
		do_move(&st, best, target);
	}
	rotate_to_min(stack_a, counts);
}
