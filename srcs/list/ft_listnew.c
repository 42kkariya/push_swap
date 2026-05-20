/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:14:03 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/16 13:15:27 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*ft_listnew(int nb, t_list **cy_list)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		ft_exit(ERROR, *cy_list);
	newnode -> nbr = nb;
	newnode -> next = NULL;
	newnode -> prev = NULL;
	return (newnode);
}
