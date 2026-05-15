/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_frag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:38:25 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/15 14:38:06 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_frag(char	*argv, t_frag *frag, t_alist **cy_list)
{
	if (!ft_free_strcmp(argv, "simple", cy_list))
	{
		frag -> sim++;
		frag -> check++;
	}
	else if (!ft_free_strcmp(argv, "medium", cy_list))
	{
		frag -> med++;
		frag -> check++;
	}
	else if (!ft_free_strcmp(argv, "complex", cy_list))
	{
		frag -> com++;
		frag -> check++;
	}
	else if (!ft_free_strcmp(argv, "adaptive", cy_list))
	{
		frag -> ada++;
		frag -> check++;
	}
	else if (!ft_free_strcmp(argv, "bench", cy_list))
		frag -> ben++;
	else
		ft_exit(ERROR, *cy_list);
	ft_frag_nbr_check(frag, cy_list);
}

int	ft_free_strcmp(char *dest, char *src, t_alist **cy_list)
{
	size_t	i;
	int		res;

	i = 0;
	while (dest[i] && src[i] && dest[i] == src[i])
		i++;
	res = (unsigned char)dest[i] - (unsigned char)src[i];
	if (res != 0)
		ft_exit(ERROR, *cy_list);
	return (res);
}

void	ft_frag_nbr_check(t_frag *frag, t_alist **cy_list)
{
	if (frag -> check >= 2)
		ft_exit(ERROR, *cy_list);
	else if (frag -> ben >= 2)
		ft_exit(ERROR, *cy_list);
	return ;
}
