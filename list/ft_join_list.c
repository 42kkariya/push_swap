/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:15:53 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/15 14:39:41 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_join_list(t_alist **cy_list)
{
	t_alist	*last;

	last = ft_listlast(*cy_list);
	last -> next = *cy_list;
	(*cy_list)->prev = last;
}
