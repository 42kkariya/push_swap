/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_check_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:10:00 by kkariya           #+#    #+#             */
/*   Updated: 2026/06/01 13:53:34 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	free_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
		free(argv[i++]);
	free(argv);
}

void	ft_argv_error(int argc, char **argv, int *map)
{
	free(map);
	free_argv(argc, argv);
	ft_printf(2, "%s", "Error\n");
	exit(ERROR);
}

static int	safe_atoi(char *nb, int *result)
{
	int		sign;
	long	res;
	size_t	i;

	res = 0;
	i = 0;
	sign = 1;
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (!(nb[i + 1] >= '0' && nb[i + 1] <= '9'))
			return (0);
		if (nb[i++] == '-')
			sign = -1;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		if (res > (long)INT_MAX / 10)
			return (0);
		res = res * 10 + (nb[i++] - '0');
	}
	if (sign * res > INT_MAX || res * sign < INT_MIN || nb[i] != '\0')
		return (0);
	*result = (int)(res * sign);
	return (1);
}

static int	check_flag(char *argv, int *strategy, int *bench)
{
	if (argv[0] != '-' || argv[1] != '-')
		return (0);
	argv += 2;
	if (!ft_strcmp(argv, "bench"))
		return (++(*bench) < 2);
	if (!ft_strcmp(argv, "simple") || !ft_strcmp(argv, "medium")
		|| !ft_strcmp(argv, "complex") || !ft_strcmp(argv, "adaptive"))
		return (++(*strategy) < 2);
	return (0);
}

int	ft_fill_map(int argc, char **argv, int *map)
{
	int	i;
	int	j;
	int	strategy;
	int	bench;

	i = 0;
	j = 0;
	strategy = 0;
	bench = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (!check_flag(argv[i], &strategy, &bench))
				return (-1);
		}
		else if (!safe_atoi(argv[i], &map[j++]))
			return (-1);
		i++;
	}
	return (j);
}
