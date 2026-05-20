/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:26:03 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/18 17:19:56 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*cy_list;
	t_list	*stack_b;
	t_frag	frag;

	cy_list = NULL;
	zerofrag(&frag);
	ft_argv_check(argc, argv, &cy_list);
	ft_make_cy_list(&cy_list, &frag, argc, argv);
	if (frag.check == 0)
		frag.ada = 1;
	stack_b = NULL;
	sort_dispatch(&cy_list, &stack_b, &frag);
	return (0);
}

// python3 -c "
// import subprocess, random

// def test(n, t=20):
// 	ops = []
// 	for _ in range(t):
// 		nums = random.sample(range(-10000,10000), n)
// 		r = subprocess.run(['./push_swap', '--medium']+list(map(str,nums)), capture_output=True, text=True)
// 		ops.append(len(r.stdout.strip().splitlines()))
// 	print(f'n={n}: min={min(ops)}, max={max(ops)}, avg={sum(ops)/len(ops):.1f}')

// test(100)
// test(500)
// "