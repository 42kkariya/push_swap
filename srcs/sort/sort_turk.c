/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:00:59 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/18 17:10:57 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// find_target: nbr が A のどこに入るかを返す
//   A を走査して node->nbr < nbr < node->next->nbr となるノードを探す
//   nbr が A の最大値より大きい場合 → min(A) のノードを返す（末尾に挿入）
//   nbr が A の最小値より小さい場合 → min(A) のノードを返す（先頭に挿入）
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

// calc_cost: B の node を A に挿入する合計コストを返す
//   rank_b = head から node までのステップ数
//   rank_a = head から target までのステップ数
//   cost_b = min(rank_b, size_b - rank_b)  ← rb か rrb のどちらが安いか
//   cost_a = min(rank_a, size_a - rank_a)  ← ra か rra のどちらが安いか
//   rank <= size/2 → forward (ra/rb)、それ以外 → backward (rra/rrb)
//   同方向 → max(cost_a, cost_b)  ← rr/rrr で同時回転できる
//   逆方向 → cost_a + cost_b
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

// best_node: B を先頭から全走査して最小コストの要素を返す
static t_list	*best_node(t_list *stack_a, t_list *stack_b)
{
	t_list	*fead;
	t_list	*result;
	int		min_cost;
	int		temp;

	fead = stack_b;
	result = stack_b;
	min_cost = calc_cost(stack_a, fead, stack_b);
	stack_b = stack_b->next;
	while (stack_b != fead)
	{
		temp = calc_cost(stack_a, fead, stack_b);
		if (min_cost > temp)
		{
			result = stack_b;
			min_cost = temp;
		}
		stack_b = stack_b->next;
	}
	return (result);
}

// rotate_to_min: A の最小値を先頭に持ってくる（turk_sort の最後に呼ぶ）
//   最小値のランクを求める
//   ランク <= size/2 → ra をランク回
//   ランク > size/2  → rra を (size - ランク) 回
static void	rotate_to_min(t_list **stack_a)
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
			ra(stack_a);
	else
		while (sz-- > rank)
			rra(stack_a);
}

// turk_sort: メイン
//   1. A の全要素を B に push する（while *stack_a: pb）
//   2. B が空になるまでループ:
//      a. best_node で最小コストの B 要素を選ぶ
//      b. find_target でその要素の挿入先を A から探す
//      c. do_move で回転 + pa
//   3. rotate_to_min で A の最小値を先頭に持ってくる
void	turk_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*best;
	t_list	*target;

	while (*stack_a)
		pb(stack_a, stack_b);
	pa(stack_a, stack_b);
	while (*stack_b)
	{
		best = best_node(*stack_a, *stack_b);
		target = find_target(*stack_a, best->nbr);
		do_move(stack_a, stack_b, best, target);
	}
	rotate_to_min(stack_a);
}
