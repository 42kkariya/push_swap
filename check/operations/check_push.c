/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:44:00 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/27 17:45:24 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
}
