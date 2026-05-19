/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:17:57 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/19 13:27:12 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split(char *str, int *wordcount)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	j = 0;
	split = malloc(sizeof(char *) * (*wordcount + 1));
	if (!split)
		ft_argv_exit(str);
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			split[j] = malloc (sizeof(char) * (ft_wordlen(&str[i]) + 1));
			if (!split[j])
				ft_free_split(str, split, j);
			split[j] = ft_cpy(split[j], &str[i]);
			j++;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

char	*ft_cpy(char *split, char *src)
{
	int	i;

	i = 0;
	while (src[i] != ' ')
	{
		split[i] = src[i];
		i++;
	}
	split[i] = '\0';
	return (split);
}

void	ft_free_split(char *str, char **split, int j)
{
	free(str);
	while (--j >= 0)
		free(split[j]);
	free(split);
	ft_printf("Error");
	exit (ERROR);
}

int	ft_wordlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != ' ')
		len++;
	return (len);
}

int	ft_word_count(char *str, int *wordcount)
{
	int	i;

	*wordcount = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			(*wordcount)++;
		i++;
	}
	return (*wordcount);
}
