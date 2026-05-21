/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:05:46 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/16 13:21:03 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_print_char(int c, int fd)
{
	char	ch;

	ch = (char)c;
	if (write(fd, &ch, 1) == -1)
		return (-1);
	return (1);
}
