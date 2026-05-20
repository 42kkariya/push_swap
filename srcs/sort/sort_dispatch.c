/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:10:09 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/20 18:10:09 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	*list_to_arr(t_list *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = stack->nbr;
		stack = stack->next;
		i++;
	}
	return (arr);
}

double	calc_disorder(t_list *stack)
{
	int		*arr;
	int		size;
	int		mistakes;
	int		i;
	int		j;

	size = stack_size(stack);
	if (size <= 1)
		return (0.0);
	arr = list_to_arr(stack, size);
	if (!arr)
		return (0.0);
	mistakes = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	free(arr);
	return ((double)mistakes / ((double)size * (size - 1) / 2));
}

static void	adaptive_sort(t_list **stack_a, t_list **stack_b)
{
	double	disorder;

	disorder = calc_disorder(*stack_a);
	if (disorder < 0.2)
		sort_simple(stack_a, stack_b);
	else if (disorder < 0.7)
		sort_turk(stack_a, stack_b);
	else
		sort_radix(stack_a, stack_b);
}

void	sort_dispatch(t_list **stack_a, t_list **stack_b, t_frag *frag)
{
	if (frag->sim)
		sort_simple(stack_a, stack_b);
	else if (frag->med)
		sort_turk(stack_a, stack_b);
	else if (frag->com)
		sort_radix(stack_a, stack_b);
	else
		adaptive_sort(stack_a, stack_b);
}
