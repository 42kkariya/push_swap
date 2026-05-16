/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:17:57 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/16 16:03:39 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split(int argc, char **argv)
{
	char	*str;
	char	**split;
	int		wordcount;
	int		i;

	str = ft_one_line(argc, argv);
	wordcount = ft_word_count(str);
	split = malloc(sizeof(char *) * wordcount);
	if (!split)
	{
		ft_pirintf("%s", "Error");
		free(str);
		exit (ERROR);
	}
	while (str[i])
	{
		if ((str[i] == ' ' || i == 0) && (str[i + 1] != ' '))
		{
			split[i] = malloc (sizeof(char) * (ft_wordlen(&str[i + 1]) + 1));
			ft_cpy()
		}
	}
}

int	ft_word_count(char *str)
{
	int	wordcount;
	int	i;

	wordcount = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || i == 0) && (str[i + 1] != ' '))
			wordcount++;
		i++;
	}
	return (wordcount);
}
