/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:42:52 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/29 16:39:08 by mtaisei          ###   ########.fr       */
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
	ft_checker(a_stack);
	checker_free_all(new_argc, new_argv, a_stack);
	return (0);
}
