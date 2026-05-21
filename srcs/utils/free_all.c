/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:52:42 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/21 12:18:18 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_all(int new_argc, char **new_argv, t_list *cy_list)
{
	int		i;
	t_list	*first;
	t_list	*next;

	i = 0;
	while (i < new_argc)
	{
		free(new_argv[i]);
		i++;
	}
	free(new_argv);
	first = cy_list->prev;
	next = cy_list->next;
	free(cy_list);
	cy_list = next;
	while (cy_list != first)
	{
		next = cy_list->next;
		free(cy_list);
		cy_list = next;
	}
	return ;
}
