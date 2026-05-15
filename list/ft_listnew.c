/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:14:03 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/15 14:39:13 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_alist	*ft_listnew(int nb, t_alist **cy_list)
{
	t_alist	*newnode;

	newnode = malloc(sizeof(t_alist));
	if (!newnode)
		ft_exit(ERROR, *cy_list);
	newnode -> nbr = nb;
	newnode -> next = NULL;
	newnode -> prev = NULL;
	return (newnode);
}
