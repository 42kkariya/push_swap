/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:56:55 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/18 15:34:58 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_rank(t_list *head, t_list *node)
{
	int	i;

	i = 0;
	while (head != node)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	stack_size(t_list *stack)
{
	return (get_rank(stack, stack->prev) + 1);
}

static void	rotate_shared(t_list **sa, t_list **sb, int *ra_n, int *rb_n)
{
	int	sz;
	int	shared;

	sz = stack_size(*sa);
	if (*ra_n * 2 <= sz && *rb_n * 2 <= stack_size(*sb))
	{
		shared = *ra_n;
		if (*rb_n < shared)
			shared = *rb_n;
		*ra_n -= shared;
		*rb_n -= shared;
		while (shared-- > 0)
			rr(sa, sb);
	}
	else if (*ra_n * 2 > sz && *rb_n * 2 > stack_size(*sb))
	{
		shared = sz - *ra_n;
		if (stack_size(*sb) - *rb_n < shared)
			shared = stack_size(*sb) - *rb_n;
		*ra_n += shared;
		*rb_n += shared;
		while (shared-- > 0)
			rrr(sa, sb);
	}
}

static void	do_rotate(t_list **sa, t_list **sb, t_list *best, t_list *target)
{
	int	rank_a;
	int	rank_b;
	int	sz_a;
	int	sz_b;

	rank_a = get_rank(*sa, target);
	rank_b = get_rank(*sb, best);
	sz_a = stack_size(*sa);
	sz_b = stack_size(*sb);
	rotate_shared(sa, sb, &rank_a, &rank_b);
	if (rank_a * 2 <= sz_a)
		while (rank_a-- > 0)
			ra(sa);
	else
		while (sz_a-- > rank_a)
			rra(sa);
	if (rank_b * 2 <= sz_b)
		while (rank_b-- > 0)
			rb(sb);
	else
		while (sz_b-- > rank_b)
			rrb(sb);
}

void	do_move(t_list **sa, t_list **sb, t_list *best, t_list *target)
{
	do_rotate(sa, sb, best, target);
	pa(sa, sb);
}
