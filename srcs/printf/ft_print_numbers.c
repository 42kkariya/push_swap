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

#include "../../includes/push_swap.h"

int	ft_print_nbr(int n, int fd)
{
	long	nb;
	int		ret;

	nb = n;
	if (nb < 0)
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		ret = ft_print_nbr_base((unsigned long)(-nb), "0123456789", fd);
		if (ret == -1)
			return (-1);
		return (1 + ret);
	}
	return (ft_print_nbr_base((unsigned long)nb, "0123456789", fd));
}

int	ft_print_unsigned(unsigned int n, int fd)
{
	return (ft_print_nbr_base((unsigned long)n, "0123456789", fd));
}

int	ft_print_hex(unsigned int n, char spec, int fd)
{
	if (spec == 'x')
		return (ft_print_nbr_base((unsigned long)n, "0123456789abcdef", fd));
	return (ft_print_nbr_base((unsigned long)n, "0123456789ABCDEF", fd));
}

int	ft_print_ptr(void *ptr, int fd)
{
	int	ret;

	if (ptr == NULL)
	{
		if (write(fd, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(fd, "0x", 2) == -1)
		return (-1);
	ret = ft_print_nbr_base((unsigned long)ptr, "0123456789abcdef", fd);
	if (ret == -1)
		return (-1);
	return (2 + ret);
}

int	ft_print_double(double n, int fd)
{
	int	integer;
	int	decimal;
	int	ret;

	integer = (int)n;
	decimal = (int)((n - integer) * 100);
	ret = 0;
	ret += ft_print_nbr(integer, fd);
	if (write(fd, ".", 1) == -1)
		return (-1);
	ret++;
	if (decimal < 10)
		write(fd, "0", 1);
	ret += ft_print_nbr(decimal, fd);
	return (ret);
}
