/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:37:12 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/14 13:33:36 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_add_back(a_list ***cy_list, a_list	*new)
{
	a_list	*last;

	if (**cy_list == NULL)
		**cy_list = new;
	else
	{
		last = ft_listlast(**cy_list);
		last -> next = new;
		new -> prev = last;
	}
}
