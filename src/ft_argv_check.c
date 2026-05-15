/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:02:36 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/15 14:40:04 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_argv_check(int argc, char **argv, t_alist **cy_list)
{
	int		i;
	int		*map;
	int		j;

	map = malloc(sizeof(int) * (argc - 1));
	if (!map)
	{
		ft_printf("%s", "Error");
		exit (ERROR);
	}
	i = 1;
	j = 0;
	while (i < argc)
	{
		if ((argv[i][0] >= '0' && argv[i][0] <= '9')
		|| ((argv[i][0] == '-' || argv[i][0] == '+')
		&& (argv[i][1] >= '0' && argv[i][1] <= '9')))
		{
			map[j] = ft_atoi(argv[i], cy_list);
			j++;
		}
		i++;
	}
	ft_nbrcheck(map, j);
	free(map);
}

void	ft_nbrcheck(int *map, int j)
{
	int	i;

	i = 0;
	if (j == 0)
	{
		free(map);
		ft_printf("%s", "Error");
		exit(ERROR);
	}
	while (i < j)
	{
		if (ft_check(map[i], &map[i + 1], j - (i + 1)))
		{
			free(map);
			ft_printf("%s", "Error");
			exit(ERROR);
		}
		i++;
	}
}

int	ft_check(int nb, int *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (nb == map[i])
			return (1);
		i++;
	}
	return (0);
}
