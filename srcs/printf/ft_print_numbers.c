/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 18:05:02 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/16 13:22:40 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_print_nbr(int n)
{
	long	nb;
	int		ret;

	nb = n;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		ret = ft_print_nbr_base((unsigned long)(-nb), "0123456789");
		if (ret == -1)
			return (-1);
		return (1 + ret);
	}
	return (ft_print_nbr_base((unsigned long)nb, "0123456789"));
}

int	ft_print_unsigned(unsigned int n)
{
	return (ft_print_nbr_base((unsigned long)n, "0123456789"));
}

int	ft_print_hex(unsigned int n, char spec)
{
	if (spec == 'x')
		return (ft_print_nbr_base((unsigned long)n, "0123456789abcdef"));
	return (ft_print_nbr_base((unsigned long)n, "0123456789ABCDEF"));
}

int	ft_print_ptr(void *ptr)
{
	int	ret;

	if (ptr == NULL)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	ret = ft_print_nbr_base((unsigned long)ptr, "0123456789abcdef");
	if (ret == -1)
		return (-1);
	return (2 + ret);
}
