/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zerofrag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:05:58 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/15 14:02:10 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	zerofrag(t_frag *frag)
{
	frag -> sim = 0;
	frag -> med = 0;
	frag -> com = 0;
	frag -> ada = 0;
	frag -> ben = 0;
	frag -> check = 0;
}
