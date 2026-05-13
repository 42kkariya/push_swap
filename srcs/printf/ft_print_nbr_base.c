/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 17:39:17 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/04 12:00:00 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr_base(unsigned long n, char *base)
{
	char	c;
	int		count;
	int		baselen;

	baselen = 0;
	while (base[baselen] != '\0')
		baselen++;
	count = 0;
	if (n >= (unsigned long)baselen)
	{
		count = ft_print_nbr_base(n / baselen, base);
		if (count == -1)
			return (-1);
	}
	c = base[n % baselen];
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}
