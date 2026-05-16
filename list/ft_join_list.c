/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:15:53 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/16 13:15:25 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_join_list(t_list **cy_list)
{
	t_list	*last;

	last = ft_listlast(*cy_list);
	last -> next = *cy_list;
	(*cy_list)->prev = last;
}
