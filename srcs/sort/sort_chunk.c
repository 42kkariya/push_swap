/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:26:38 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/21 17:11:11 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** chunk sort: O(n√n)
**
** 概要:
**   n 要素を √n 個のチャンク（各サイズ √n）に分割して処理する
**   push フェーズ: A のチャンクを順番に B へ push する
**   pull フェーズ: B から最大値を探して A へ戻す
**
** push フェーズ: O(n√n)
**   チャンク数 √n × 各チャンクのスキャン O(n) = O(n√n) ops
**
** pull フェーズ: O(n√n)
**   n 要素 × チャンク内の最大値探索 O(√n) = O(n√n) ops
*/

/*
** normalize: A の各要素に 0〜n-1 のランクを付与する
**   元の nbr 値をランクで上書きする（radix と同じ方式）
**   O(n^2) だが push_swap ops には影響しない
*/
// static void	normalize(t_list *stack, int size)


/*
** push_chunk: ランクが [lo, hi) の要素を A から B へ push する
**   A を1周スキャンし、範囲内の要素を pb、範囲外を ra
**   B に push した要素は B の先頭に積まれるので逆順になる
**   push 中に B の真ん中付近にある場合 rb して分散させる（コスト削減）
**   O(n) ops per chunk × √n chunks = O(n√n)
*/
// static void	push_chunk(t_stacks, int lo, int hi)

static void	push_chunk(t_stacks *st, int lo, int hi)
{
	int	size;
	int	i;

	size = stack_size(*st->a);
	i = 0;
	while (i < size)
	{
		if (((*st->a)->nbr) >= lo && ((*st->a)->nbr) <= hi)
		{
			pb(st->a, st->b, st->cnt);
			if ((*st->b)->nbr >= (lo + hi) / 2)
				rb(st->b, st->cnt);
		}
		else
			ra(st->a, st->cnt);
		i++;
	}
}


/*
** pull_all: B に積まれた要素を最大値順に A へ戻す
**   B の中から最大ランクの要素を探す → rb/rrb で先頭に持ってくる → pa
**   O(√n) ops per element × n elements = O(n√n)
*/
// static void	pull_all(t_list **a, t_list **b, t_counts *cnt, int size)

static t_list	*find_max(t_list *b)
{
	t_list	*head;
	t_list	*max;
	t_list	*curr;

	head = b;
	max = head;
	curr = head->next;
	while (curr != head)
	{
		if (curr->nbr > max->nbr)
			max = curr;
		curr = curr->next;
	}
	return (max);
}

static void	pull_all(t_stacks *st)
{
	t_list	*max;
	int		rank;
	int		sz;

	while (*st->b)
	{
		max = find_max(*st->b);
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

/*
** sort_chunk: エントリポイント
**   1. normalize で全要素をランク化
**   2. チャンクサイズ = √n を計算
**   3. push_chunk を √n 回呼んで全要素を B へ
**   4. pull_all で B から A へ最大値順に戻す
**   5. A の先頭が最小値になるよう rotate して完了
*/
// void	sort_chunk(t_list **stack_a, t_list **stack_b, t_counts *counts)

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

static void	push_all_chunks(t_stacks *st, int size)
{
	int	chunk;
	int	lo;
	int	hi;

	chunk = isqrt(size);
	lo = 0;
	while (lo < size)
	{
		hi = lo + chunk - 1;
		if (hi >= size)
			hi = size - 1;
		push_chunk(st, lo, hi);
		lo += chunk;
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
	push_all_chunks(&st, size);
	pull_all(&st);
	rotate_to_min(stack_a, counts);
}
