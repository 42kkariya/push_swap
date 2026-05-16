/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:28:00 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/16 13:15:30 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		res = res * 10 + (nb[i] - '0');
		i++;
	}
	if (sign * res > INT_MAX || res * sign < INT_MIN || nb[i] != '\0')
		ft_exit(ERROR, *cy_list);
	return (res * sign);
}
