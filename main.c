/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:26:03 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/14 17:32:53 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	a_list	*cy_list;
	t_frag	frag;
	int		check;

	cy_list = NULL;
	zerofrag(&frag);
	ft_argv_check(argc, argv);
	if (ft_make_cy_list(&cy_list, &frag, argc, argv))
		ft_exit(ERROR);
}
