/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:26:03 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/21 11:10:23 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*cy_list;
	t_frag	frag;
	char	**new_argv;
	int		new_argc;
	t_list		*cy_list;
	t_list		*stack_b;
	t_frag		frag;
	t_counts	counts;
	double		disorder;

	cy_list = NULL;
	new_argv = make_new_argv(argc, argv, &new_argc);
	zerofrag(&frag);
	ft_argv_check(new_argc, new_argv, &cy_list);
	ft_make_cy_list(&cy_list, &frag, new_argc, new_argv);
	zerocount(&counts);
	ft_argv_check(argc, argv, &cy_list);
	ft_make_cy_list(&cy_list, &frag, argc, argv);
	if (frag.check == 0)
		frag.ada = 1;
	stack_b = NULL;
	if (is_sorted(cy_list))
		return (0);
	disorder = calc_disorder(cy_list);
	sort_dispatch(&cy_list, &stack_b, &frag, &counts);
	if (frag.ben)
		print_bench(&frag, &counts, disorder);
	return (0);
}
