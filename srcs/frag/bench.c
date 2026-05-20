/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 19:14:55 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/20 19:14:55 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	sum_counts(t_counts *counts)
{
	int	sum;

	sum = 0;
	sum += counts->cnt_sa + counts->cnt_sb + counts->cnt_ss;
	sum += counts->cnt_pa + counts->cnt_pb;
	sum += counts->cnt_ra + counts->cnt_rb + counts->cnt_rr;
	sum += counts->cnt_rra + counts->cnt_rrb + counts->cnt_rrr;
	return (sum);
}

static void	print_strategy(t_frag *frag, double disorder)
{
	if (frag->sim)
		ft_printf(2, "%s", "[bench] strategy: Simple / O(n^2)\n");
	else if (frag->med)
		ft_printf(2, "%s", "[bench] strategy: Medium / O(n*sqrt(n))\n");
	else if (frag->com)
		ft_printf(2, "%s", "[bench] strategy: Complex / O(n log n)\n");
	else if (disorder < 0.2)
		ft_printf(2, "%s", "[bench] strategy: Adaptive / O(n^2)\n");
	else if (disorder < 0.7)
		ft_printf(2, "%s", "[bench] strategy: Adaptive / O(n*sqrt(n))\n");
	else
		ft_printf(2, "%s", "[bench] strategy: Adaptive / O(n log n)\n");
}

static void	print_ops(t_counts *counts)
{
	ft_printf(2, "%s", "[bench] ");
	ft_printf(2, "sa: %d ", counts->cnt_sa);
	ft_printf(2, "sb: %d ", counts->cnt_sb);
	ft_printf(2, "ss: %d ", counts->cnt_ss);
	ft_printf(2, "pa: %d ", counts->cnt_pa);
	ft_printf(2, "pb: %d ", counts->cnt_pb);
	ft_printf(2, "ra: %d ", counts->cnt_ra);
	ft_printf(2, "rb: %d ", counts->cnt_rb);
	ft_printf(2, "rr: %d ", counts->cnt_rr);
	ft_printf(2, "rra: %d ", counts->cnt_rra);
	ft_printf(2, "rrb: %d ", counts->cnt_rrb);
	ft_printf(2, "rrr: %d\n", counts->cnt_rrr);
}

void	print_bench(t_frag *frag, t_counts *counts, double disorder)
{
	ft_printf(2, "%s", "[bench] disorder: ");
	ft_printf(2, "%f", disorder * 100);
	ft_printf(2, "%s", "%\n");
	print_strategy(frag, disorder);
	ft_printf(2, "[bench] total_ops: %d\n", sum_counts(counts));
	print_ops(counts);
}
