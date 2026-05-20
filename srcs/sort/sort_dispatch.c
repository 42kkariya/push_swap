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

static int	count_mistakes(int *arr, int size)
{
	int	mistakes;
	int	i;
	int	j;

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
	return (mistakes);
}

double	calc_disorder(t_list *stack)
{
	int		*arr;
	int		size;
	int		mistakes;

	size = stack_size(stack);
	if (size <= 1)
		return (0.0);
	arr = list_to_arr(stack, size);
	if (!arr)
		return (0.0);
	mistakes = count_mistakes(arr, size);
	free(arr);
	return ((double)mistakes / ((double)size * (size - 1) / 2));
}

static void	adaptive_sort(t_list **stack_a, t_list **stack_b, t_counts *counts)
{
	double	disorder;

	disorder = calc_disorder(*stack_a);
	if (disorder < 0.2)
		sort_simple(stack_a, stack_b, counts);
	else if (disorder < 0.7)
		sort_turk(stack_a, stack_b, counts);
	else
		sort_radix(stack_a, stack_b, counts);
}

void	sort_dispatch(t_list **s_a, t_list **s_b, t_frag *frag, t_counts *cnt)
{
	if (frag->sim)
		sort_simple(s_a, s_b, cnt);
	else if (frag->med)
		sort_turk(s_a, s_b, cnt);
	else if (frag->com)
		sort_radix(s_a, s_b, cnt);
	else
		adaptive_sort(s_a, s_b, cnt);
}
