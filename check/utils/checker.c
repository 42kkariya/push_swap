/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:51:35 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/31 13:24:14 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	ft_checker(t_list **a_stack)
{
	t_list	*b_stack;
	char	*line;

	b_stack = NULL;
	line = "test";
	while (1)
	{
		line = checker_get_next_line(0);
		if (line == NULL)
			break ;
		if (!linecheck(line))
			return (free_b_stack(b_stack));
		checker_swap(line, a_stack, &b_stack);
		free(line);
	}
	check_stack(*a_stack, b_stack);
	free_b_stack(b_stack);
	return (FALSE);
}

int	linecheck(char *line)
{
	if (!checker_strcmp(line, "sa\n") || !checker_strcmp(line, "sb\n")
		|| !checker_strcmp(line, "ss\n") || !checker_strcmp(line, "pa\n")
		|| !checker_strcmp(line, "pb\n") || !checker_strcmp(line, "ra\n")
		|| !checker_strcmp(line, "rb\n") || !checker_strcmp(line, "rr\n")
		|| !checker_strcmp(line, "rra\n") || !checker_strcmp(line, "rrb\n")
		|| !checker_strcmp(line, "rrr\n"))
		return (TRUE);
	free (line);
	return (FALSE);
}

int	free_b_stack(t_list *b_stack)
{
	t_list	*next;

	if (b_stack == NULL)
		return (TRUE);
	b_stack->prev->next = NULL;
	while (b_stack)
	{
		next = b_stack->next;
		free(b_stack);
		b_stack = next;
	}
	return (TRUE);
}

void	check_stack(t_list *a_stack, t_list *b_stack)
{
	if (is_sorted(a_stack) && empty(b_stack))
	{
		write(1, "OK\n", 3);
		return ;
	}
	write(1, "KO\n", 3);
}

void	checker_swap(char *line, t_list **a_stack, t_list **b_stack)
{
	if (!checker_strcmp(line, "sa\n"))
		sa(a_stack);
	else if (!checker_strcmp(line, "sb\n"))
		sb(b_stack);
	else if (!checker_strcmp(line, "ss\n"))
		ss(a_stack, b_stack);
	else if (!checker_strcmp(line, "pa\n"))
		pa(a_stack, b_stack);
	else if (!checker_strcmp(line, "pb\n"))
		pb(a_stack, b_stack);
	else if (!checker_strcmp(line, "ra\n"))
		ra(a_stack);
	else if (!checker_strcmp(line, "rb\n"))
		rb(b_stack);
	else if (!checker_strcmp(line, "rr\n"))
		rr(a_stack, b_stack);
	else if (!checker_strcmp(line, "rra\n"))
		rra(a_stack);
	else if (!checker_strcmp(line, "rrb\n"))
		rrb(b_stack);
	else if (!checker_strcmp(line, "rrr\n"))
		rrr(a_stack, b_stack);
}
