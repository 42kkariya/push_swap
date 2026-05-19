/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_new_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 21:57:10 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/16 22:13:13 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**make_new_argv(int argc, char **argv, int *wordcount)
{
	char	*str;
	char	**split;

	*wordcount = 0;
	str = ft_one_line(argc, argv);
	*wordcount = ft_word_count(str, wordcount);
	if (*wordcount == 0)
		ft_argv_exit(str);
	split = ft_split(str, wordcount);
	free (str);
	return (split);
}
