/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 14:27:38 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/14 14:27:38 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_list **from, t_list **to)
{
	t_list	*node;
	t_list	*from_tail;
	t_list	*to_tail;

	if (!*from)
		return ;
	node = *from;
	from_tail = node->prev;
	if (node->next == node)
		*from = NULL;
	else
	{
		*from = node->next;
		(*from)->prev = from_tail;
		from_tail->next = *from;
	}
	if (!*to)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		to_tail = (*to)->prev;
		node->next = *to;
		(*to)->prev = node;
		node->prev = to_tail;
		to_tail->next = node;
	}
	*to = node;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}