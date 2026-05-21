/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:29:35 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/21 11:36:51 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_swap(t_list **s_a, t_frag frag)
{
	t_counts	counts;
	double		disorder;

	zerocount(&counts);
	if (frag.check == 0)
		frag.ada = 1;
	if (is_sorted(*s_a))
		return ;
	disorder = calc_disorder(*s_a);
	sort_dispatch(s_a, &frag, &counts);
	if (frag.ben)
		print_bench(&frag, &counts, disorder);
	return ;
}
