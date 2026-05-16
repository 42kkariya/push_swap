/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:27:15 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/16 13:15:26 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_listlast(t_list *cy_list)
{
	while (cy_list -> next != NULL)
	{
		cy_list = cy_list -> next;
	}
	return (cy_list);
}
