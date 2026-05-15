/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:27:15 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/15 14:39:29 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_alist	*ft_listlast(t_alist *cy_list)
{
	while (cy_list -> next != NULL)
	{
		cy_list = cy_list -> next;
	}
	return (cy_list);
}
