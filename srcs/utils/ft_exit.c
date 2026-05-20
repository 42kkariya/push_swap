/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:51:50 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/16 13:15:30 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_exit(int error, t_list *cy_list)
{
	t_list	*p;

	while (cy_list)
	{
		p = cy_list -> next;
		free (cy_list);
		cy_list = p;
	}
	ft_printf(2, "%s", "Error\n");
	exit (error);
}
