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
	sort_turk(&cy_list, &stack_b);
	return (0);
}
