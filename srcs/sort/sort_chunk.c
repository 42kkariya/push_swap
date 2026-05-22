/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:26:38 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/22 14:40:17 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	safe_stack_size(t_list *stack)
{
	if (!stack)
		return (0);
	return (stack_size(stack));
}

static void	pull_all(t_stacks *st)
{
	t_list	*max;
	t_list	*curr;
	int		rank;
	int		sz;

	while (*st->b)
	{
		max = *st->b;
		curr = (*st->b)->next;
		while (curr != *st->b)
		{
			if (curr->nbr > max->nbr)
				max = curr;
			curr = curr->next;
		}
		rank = get_rank(*st->b, max);
		sz = stack_size(*st->b);
		if (rank * 2 <= sz)
			while (rank-- > 0)
				rb(st->b, st->cnt);
		else
			while (sz-- > rank)
				rrb(st->b, st->cnt);
		pa(st->a, st->b, st->cnt);
	}
}

static int	isqrt(int n)
{
	int	lo;
	int	hi;
	int	mid;

	lo = 1;
	hi = n;
	while (lo < hi)
	{
		mid = (lo + hi + 1) / 2;
		if (mid * mid <= n)
			lo = mid;
		else
			hi = mid - 1;
	}
	return (lo);
}

static void	push_dynamic_window(t_stacks *st, int size)
{
	int	window;
	int	pushed;

	window = isqrt(size) * 3 / 2;
	if (window < 2)
		window = 2;
	while (*st->a)
	{
		pushed = safe_stack_size(*st->b);
		if ((*st->a)->nbr <= pushed)
		{
			pb(st->a, st->b, st->cnt);
			if ((*st->b)->next != *st->b)
				rb(st->b, st->cnt);
		}
		else if ((*st->a)->nbr <= pushed + window)
			pb(st->a, st->b, st->cnt);
		else
			ra(st->a, st->cnt);
	}
}

void	sort_chunk(t_list **stack_a, t_list **stack_b, t_counts *counts)
{
	t_stacks	st;
	int			size;
	int			*arr;

	size = stack_size(*stack_a);
	arr = to_index(*stack_a, size);
	if (!arr)
		return ;
	free(arr);
	st.a = stack_a;
	st.b = stack_b;
	st.cnt = counts;
	push_dynamic_window(&st, size);
	pull_all(&st);
	rotate_to_min(stack_a, counts);
}
