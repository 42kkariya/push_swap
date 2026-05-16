/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:56:55 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/16 17:56:55 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// get_rank: head から node までのステップ数を返す（0-indexed）
//   head == node のとき 0 を返す
static int	get_rank(t_list *head, t_list *node)
{
}

// stack_size: 循環リストのサイズを返す
static int	stack_size(t_list *stack)
{
}

// do_rotate: best（B 要素）と target（A の挿入先）を最適な方向で回転させる
//   get_rank で rank_b, rank_a を求め、size と比較して方向を決める
//   同方向（どちらも forward or どちらも backward）:
//     rr または rrr を min(cost_a, cost_b) 回実行
//     残りを rb/rrb または ra/rra で個別に処理
//   逆方向:
//     B を rb/rrb で cost_b 回 → A を ra/rra で cost_a 回
static void	do_rotate(t_list **sa, t_list **sb, t_list *best, t_list *target)
{
}

// do_move: best を A の target の直前に挿入する
//   do_rotate で B と A を回転させてから pa する
void	do_move(t_list **stack_a, t_list **stack_b, t_list *best, t_list *target)
{
}
