/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_cy_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:39:58 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/14 17:32:19 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_make_cy_list(a_list	**cy_list, t_frag *frag, int argc, char **argv)
{
	size_t	i;
	int		check;

	i = 1;
	check = 0;
	while (i < argc)
	{
		if ((argv[i][0] >= '0' && argv[i][0] <= '9') || argv[i] == '-')
			ft_list_add_back(&cy_list, ft_listnew(ft_atoi(argv[i++])));
		else if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			frag = ft_check_frag(frag, &argv[i++][2]);
			check++;
		}
		else
			ft_exit(ERROR);
	}
	ft_join_list(cy_list);
	return (check);
}
