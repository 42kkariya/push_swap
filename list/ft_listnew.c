/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:14:03 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/14 13:26:09 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

a_list	*ft_listnew(int nb)
{
	a_list	*newnode;

	newnode = malloc(sizeof(a_list));
	newnode -> nbr = nb;
	newnode -> next = NULL;
	return (newnode);
}
