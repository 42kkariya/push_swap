/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:57:10 by kkariya           #+#    #+#             */
/*   Updated: 2026/06/01 13:56:57 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	zerofrag(t_frag *frag)
{
	frag->sim = 0;
	frag->med = 0;
	frag->com = 0;
	frag->ada = 0;
	frag->ben = 0;
	frag->check = 0;
}

void	zerocount(t_counts *counts)
{
	counts->cnt_sa = 0;
	counts->cnt_sb = 0;
	counts->cnt_ss = 0;
	counts->cnt_pa = 0;
	counts->cnt_pb = 0;
	counts->cnt_ra = 0;
	counts->cnt_rb = 0;
	counts->cnt_rr = 0;
	counts->cnt_rra = 0;
	counts->cnt_rrb = 0;
	counts->cnt_rrr = 0;
}

int	ft_strcmp(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (dest[i] && src[i] && dest[i] == src[i])
		i++;
	return ((unsigned char)dest[i] - (unsigned char)src[i]);
}

void	ft_check_frag(char	*argv, t_frag *frag)
{
	if (!ft_strcmp(argv, "simple"))
	{
		frag->sim++;
		frag->check++;
	}
	else if (!ft_strcmp(argv, "medium"))
	{
		frag->med++;
		frag->check++;
	}
	else if (!ft_strcmp(argv, "complex"))
	{
		frag->com++;
		frag->check++;
	}
	else if (!ft_strcmp(argv, "adaptive"))
	{
		frag->ada++;
		frag->check++;
	}
	else if (!ft_strcmp(argv, "bench"))
		frag->ben++;
}
