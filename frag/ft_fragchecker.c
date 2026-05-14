/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fragchecker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 14:51:13 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/14 14:57:50 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	sim_check(char *str, char *sim)
{
	size_t	i;
	size_t	count;
	size_t	len;

	i = 0;
	count = 0;
	len = 0;
	while (sim[len])
		len++;
	while (str[i])
	{
		if (str[i] == sim[i])
			count++;
		i++;
	}
	if (count == len)
		return (1);
	else
		return (0);
}

size_t	med_check(char *str, char *med)
{
	size_t	i;
	size_t	count;
	size_t	len;

	i = 0;
	count = 0;
	len = 0;
	while (med[len])
		len++;
	while (str[i])
	{
		if (str[i] == med[i])
			count++;
		i++;
	}
	if (count == len)
		return (1);
	else
		return (0);
}

size_t	com_check(char *str, char *com)
{
	size_t	i;
	size_t	count;
	size_t	len;

	i = 0;
	count = 0;
	len = 0;
	while (com[len])
		len++;
	while (str[i])
	{
		if (str[i] == com[i])
			count++;
		i++;
	}
	if (count == len)
		return (1);
	else
		return (0);
}

size_t	ada_check(char *str, char *ada)
{
	size_t	i;
	size_t	count;
	size_t	len;

	i = 0;
	count = 0;
	len = 0;
	while (ada[len])
		len++;
	while (str[i])
	{
		if (str[i] == ada[i])
			count++;
		i++;
	}
	if (count == len)
		return (1);
	else
		return (0);
}
