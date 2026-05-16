/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_cy_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:39:58 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/16 21:47:01 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_cy_list(t_list	**cy_list, t_frag *frag, int argc, char **argv)
{
	int	i;
	int	nb;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			ft_check_frag(&argv[i][2], frag, cy_list);
		else if ((argv[i][0] >= '0' && argv[i][0] <= '9')
				|| argv[i][0] == '-' || argv[i][0] == '+')
		{
			nb = ft_atoi(argv[i], cy_list);
			ft_list_add_back(cy_list, ft_listnew(nb, cy_list));
		}
		else
			ft_exit(ERROR, *cy_list);
		i++;
	}
	ft_join_list(cy_list);
}
