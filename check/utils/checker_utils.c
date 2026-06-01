/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:56:44 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/29 17:39:03 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	checker_strcmp(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i] && dest[i] && src[i] == dest[i])
		i++;
	return ((unsigned char)src[i] - (unsigned char)dest[i]);
}

int	is_sorted(t_list *a_stack)
{
	t_list	*last;
	int		next_nbr;

	if (!a_stack)
		return (TRUE);
	last = a_stack->prev;
	last->next = NULL;
	while (a_stack->next != NULL)
	{
		next_nbr = a_stack->next->nbr;
		if (next_nbr < a_stack->nbr)
			return (FALSE);
		a_stack = a_stack->next;
	}
	return (TRUE);
}

int	empty(t_list *b_stack)
{
	if (b_stack == NULL)
			return (TRUE);
	return (FALSE);
}

void	checker_free_all(int new_argc, char **new_argv, t_list *a_stack)
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
	if (!a_stack)
		return ;
	while (a_stack)
	{
		next = a_stack->next;
		free(a_stack);
		a_stack = next;
	}
	return ;
}
