/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:15:53 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/14 15:24:12 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_join_list(a_list **cy_list)
{
	a_list	*last;

	last = ft_listlast(*cy_list);
	last -> next = *cy_list;
	(*cy_list)->prev = last;
}
