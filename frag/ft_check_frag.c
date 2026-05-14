/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_frag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:38:25 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/14 15:56:36 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_frag	*ft_check_frag(t_frag *frag, char *str)
{
	if (sim_check(str, "simple"))
		frag -> sim = 1;
	else if (med_check(str, "medium"))
		frag -> med = 1;
	else if (com_check(str, "complex"))
		frag -> com = 1;
	else if (ada_check(str, "adaptive"))
		frag -> ada = 1;
	else
		ft_exit(ERROR);
	return (frag);
}
