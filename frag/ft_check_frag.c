/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_frag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:38:25 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/16 13:15:24 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_frag(char	*argv, t_frag *frag, t_list **cy_list)
{
	if (!ft_strcmp(argv, "simple"))
	{
		frag -> sim++;
		frag -> check++;
	}
	else if (!ft_strcmp(argv, "medium"))
	{
		frag -> med++;
		frag -> check++;
	}
	else if (!ft_strcmp(argv, "complex"))
	{
		frag -> com++;
		frag -> check++;
	}
	else if (!ft_strcmp(argv, "adaptive"))
	{
		frag -> ada++;
		frag -> check++;
	}
	else if (!ft_strcmp(argv, "bench"))
		frag -> ben++;
	else
		ft_exit(ERROR, *cy_list);
	ft_frag_nbr_check(frag, cy_list);
}

int	ft_strcmp(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (dest[i] && src[i] && dest[i] == src[i])
		i++;
	return ((unsigned char)dest[i] - (unsigned char)src[i]);
}

void	ft_frag_nbr_check(t_frag *frag, t_list **cy_list)
{
	if (frag -> check >= 2)
		ft_exit(ERROR, *cy_list);
	else if (frag -> ben >= 2)
		ft_exit(ERROR, *cy_list);
	return ;
}
