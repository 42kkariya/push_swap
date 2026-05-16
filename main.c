/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:26:03 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/16 13:15:19 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*cy_list;
	t_list	*stack_b;
	t_list	*current;
	t_frag	frag;

	cy_list = NULL;
	zerofrag(&frag);
	ft_argv_check(argc, argv, &cy_list);
	ft_make_cy_list(&cy_list, &frag, argc, argv);
	if (frag.check == 0)
		frag.ada = 1;
	stack_b = NULL;
	sort_simple(&cy_list, &stack_b);
	current = cy_list;
	while (current->next != cy_list)
	{
		ft_printf("%d, ", current->nbr);
		current = current->next;
	}
	ft_printf("%d\n", current->nbr);
	return (0);
}
