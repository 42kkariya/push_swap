/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:00:49 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/18 15:40:32 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	*bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if ((arr[i] > arr[j]) && (i != j))
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

static void	assign_index(t_list *stack, int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (stack->nbr == arr[j])
			{
				stack->nbr = j;
				break ;
			}
			j++;
		}
		stack = stack->next;
		i++;
	}
}

static int	*to_index(t_list *stack, int size)
{
	int		*arr;
	int		i;

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
	arr = bubble_sort(arr, size);
	assign_index(stack, arr, size);
	return (arr);
}

void	sort_radix(t_list **stack_a, t_list **stack_b, t_counts *counts)
{
	int	i;
	int	bit;
	int	size;
	int	*arr;

	size = stack_size(*stack_a);
	arr = to_index(*stack_a, size);
	bit = 0;
	while ((size - 1) >> bit)
	{
		i = 0;
		while (i < size)
		{
			if (((*stack_a)->nbr >> bit) & 1)
				ra(stack_a, counts);
			else
				pb(stack_a, stack_b, counts);
			i++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, counts);
		bit++;
	}
	free(arr);
}
