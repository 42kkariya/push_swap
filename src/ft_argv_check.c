/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:02:36 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/14 17:22:50 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_argv_check(int argc, char **argv)
{
	size_t	i;
	int		*map;
	int		nbr;

	map = malloc(sizeof(int) * (argc - 1));
	if (!map)
		ft_exit(ERROR);
	i = 1;
	while (i < argc)
	{
		if ((argv[i][0] >= '0' && argv[i][0] <= '9') || argv[i][0] == '-')
		{
			map[i] = ft_atoi(argv[i]);
		}
		i++;
	}
	ft_nbrcheck(map, argc - 1);
	free(map);
	return ;
}

void	ft_nbrcheck(int *map, int size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (ft_check(map[i], &map[i + 1], size - (i + 1)))
		{
			free(map);
			ft_exit(ERROR);
		}
		i++;
	}
}

int	ft_check(int nb, int *map, int size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (nb == map[i])
			return (1);
		i++;
	}
	return (0);
}
