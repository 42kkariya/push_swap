/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:51:50 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/15 14:40:44 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(int error, t_alist *cy_list)
{
	t_alist	*p;

	while (cy_list)
	{
		p = cy_list -> next;
		free (cy_list);
		cy_list = p;
	}
	ft_printf("%s", "Error");
	exit (ERROR);
}
