/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 00:00:00 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/24 00:00:00 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_exit(int error, t_list *cy_list)
{
	t_list	*p;

	while (cy_list)
	{
		p = cy_list->next;
		free (cy_list);
		cy_list = p;
	}
	ft_printf(2, "%s", "Error\n");
	exit (error);
}

void	free_all(int new_argc, char **new_argv, t_list *cy_list)
{
	int		i;
	t_list	*next;

	i = 0;
	while (i < new_argc)
	{
		free(new_argv[i]);
		i++;
	}
	free(new_argv);
	if (!cy_list)
		return ;
	cy_list->prev->next = NULL;
	while (cy_list)
	{
		next = cy_list->next;
		free(cy_list);
		cy_list = next;
	}
	return ;
}

void	push_swap(t_list **s_a, t_frag frag)
{
	t_counts	counts;
	double		disorder;

	zerocount(&counts);
	if (frag.check == 0)
		frag.ada = 1;
	disorder = calc_disorder(*s_a);
	if (!is_sorted(*s_a))
		sort_dispatch(s_a, &frag, &counts);
	if (frag.ben)
		print_bench(&frag, &counts, disorder);
	return ;
}
