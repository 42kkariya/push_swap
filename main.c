/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:26:03 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/21 11:51:59 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*cy_list;
	t_frag	frag;
	char	**new_argv;
	int		new_argc;

	cy_list = NULL;
	new_argv = make_new_argv(argc, argv, &new_argc);
	zerofrag(&frag);
	ft_argv_check(new_argc, new_argv, &cy_list);
	ft_make_cy_list(&cy_list, &frag, new_argc, new_argv);
	push_swap(&cy_list, frag);
	free_all(new_argc, new_argv, cy_list);
	return (0);
}
