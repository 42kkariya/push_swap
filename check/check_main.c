/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:42:52 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/31 13:24:57 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_frag	frag;
	char	**new_argv;
	int		new_argc;

	if (argc == 1)
		return (0);
	a_stack = NULL;
	new_argv = make_new_argv(argc, argv, &new_argc);
	zerofrag(&frag);
	ft_argv_check(new_argc, new_argv, &a_stack);
	ft_make_cy_list(&a_stack, &frag, new_argc, new_argv);
	if (ft_fragcheck(a_stack, frag, new_argv, new_argc))
		return (1);
	if (ft_checker(&a_stack))
	{
		if (a_stack != NULL)
			a_stack->prev->next = NULL;
		checker_free_all(new_argc, new_argv, a_stack);
		ft_printf(2, "Error");
		return (1);
	}
	checker_free_all(new_argc, new_argv, a_stack);
	return (0);
}

int	ft_fragcheck(t_list *a_stack,
					t_frag frag, char **new_argv, int	new_argc)
{
	int		i;
	t_list	*next;

	i = 0;
	if (frag.ada != 0 || frag.ben != 0 || frag.com != 0
		|| frag.med != 0 || frag.sim != 0)
	{
		while (i < new_argc)
		{
			free(new_argv[i]);
			i++;
		}
		free(new_argv);
		if (a_stack != NULL)
			a_stack->prev->next = NULL;
		while (a_stack)
		{
			next = a_stack->next;
			free(a_stack);
			a_stack = next;
		}
		ft_printf(2, "Error");
		return (TRUE);
	}
	return (FALSE);
}
