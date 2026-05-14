/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:28:00 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/14 17:23:32 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *nb)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	if (*nb == '-' || *nb == '+')
	{
		nb++;
		if (*nb >= '0' && *nb <= '9')
			sign = -1;
		else
			ft_exit(ERROR);
	}
	while (*nb >= '0' && *nb <= '9')
	{
		res = res * 10 + (*nb - '0');
		nb++;
	}
	if (res > INT_MAX || res < INT_MIN)
		ft_exit(ERROR);
	return (res * sign);
}
