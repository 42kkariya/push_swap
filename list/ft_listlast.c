/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:27:15 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/14 13:30:19 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

a_list	*ft_listlast(a_list *cy_list)
{
	while (cy_list -> next != NULL)
	{
		cy_list = cy_list -> next;
	}
	return (cy_list);
}
