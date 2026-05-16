/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:00:59 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/16 18:00:59 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// find_target: nbr が A のどこに入るかを返す
//   A を走査して node->nbr < nbr < node->next->nbr となるノードを探す
//   nbr が A の最大値より大きい場合 → min(A) のノードを返す（末尾に挿入）
//   nbr が A の最小値より小さい場合 → min(A) のノードを返す（先頭に挿入）
static t_list	*find_target(t_list *stack_a, int nbr)
{
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
}

// best_node: B を先頭から全走査して最小コストの要素を返す
static t_list	*best_node(t_list *stack_a, t_list *stack_b)
{
}

// rotate_to_min: A の最小値を先頭に持ってくる（turk_sort の最後に呼ぶ）
//   最小値のランクを求める
//   ランク <= size/2 → ra をランク回
//   ランク > size/2  → rra を (size - ランク) 回
static void	rotate_to_min(t_list **stack_a)
{
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
}
