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

static t_list	*detach(t_list **from)
{
	t_list	*node;
	t_list	*tail;

	if (!*from)
		return (NULL);
	node = *from;
	tail = node->prev;
	if (node->next == node)
		*from = NULL;
	else
	{
		*from = node->next;
		(*from)->prev = tail;
		tail->next = *from;
	}
	return (node);
}

static void	attach(t_list *node, t_list **to)
{
	t_list	*tail;

	if (!node)
		return ;
	if (!*to)
	{
		node->next = node;
		node->prev = node;
	}
	else
	{
		tail = (*to)->prev;
		node->next = *to;
		(*to)->prev = node;
		node->prev = tail;
		tail->next = node;
	}
	*to = node;
}

static void	push(t_list **from, t_list **to)
{
	attach(detach(from), to);
}

void	pa(t_list **stack_a, t_list **stack_b, t_counts *counts)
{
	push(stack_b, stack_a);
	counts->cnt_pa++;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, t_counts *counts)
{
	push(stack_a, stack_b);
	counts->cnt_pb++;
	write(1, "pb\n", 3);
}
