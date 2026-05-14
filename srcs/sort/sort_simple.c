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

static t_list	*serch_min(t_list **stack)
{
	t_list	*result;
	t_list	*first;

	first = (*stack);
	result = (*stack);
	while ((*stack)->next != first)
	{
		if ((*stack)->nbr < (result->nbr))
			result = (*stack);
		*stack = (*stack)->next;
	}
	return (result);
}

static void	rotate_list(t_list **stack)
{
	t_list	*min_value;

	min_value = serch_min(stack);
	while ((*stack)->nbr == min_value->nbr)
	{
		ra(stack);
	}
}
//   1. stack_a の中から最小値を探す
//   2. 最小値が先頭に来るように ra / rra で回転
//   3. pb で stack_b に押し出す
//   4. 1〜3を繰り返して全部 stack_b に移す（stack_b は降順に積まれる）
//   5. pa を繰り返して全部 stack_a に戻す（昇順になる）