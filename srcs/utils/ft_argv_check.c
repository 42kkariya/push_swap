/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:02:36 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/16 21:46:35 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_argv_check(int argc, char **argv, t_list **cy_list)
{
	int		*map;
	int		j;

	map = malloc(sizeof(int) * argc);
	if (!map)
		ft_argv_error(argc, argv, NULL);
	j = ft_fill_map(argc, argv, map);
	if (j < 0)
		ft_argv_error(argc, argv, map);
	(void)cy_list;
	ft_nbrcheck(map, j, argc, argv);
	free(map);
}

void	ft_nbrcheck(int *map, int j, int argc, char **argv)
{
	int	i;

	i = 0;
	if (j == 0)
		ft_argv_error(argc, argv, map);
	while (i < j)
	{
		if (ft_check(map[i], &map[i + 1], j - (i + 1)))
			ft_argv_error(argc, argv, map);
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

int	ft_atoi(char *nb, t_list **cy_list)
{
	int		sign;
	long	res;
	size_t	i;

	res = 0;
	i = 0;
	sign = 1;
	if (nb[i] == '-' || nb[i] == '+')
	{
		if ((nb[i + 1] >= '0' && nb[i + 1] <= '9') && nb[i] == '-')
			sign = -1;
		else if (!(nb[i + 1] >= '0' && nb[i + 1] <= '9'))
			ft_exit(ERROR, *cy_list);
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		if (res > (long)INT_MAX / 10)
			ft_exit(ERROR, *cy_list);
		res = res * 10 + (nb[i] - '0');
		i++;
	}
	if (sign * res > INT_MAX || res * sign < INT_MIN || nb[i] != '\0')
		ft_exit(ERROR, *cy_list);
	return (res * sign);
}
