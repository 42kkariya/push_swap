/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_new_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 21:57:10 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/24 00:00:00 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_argv_exit(char *str)
{
	free(str);
	ft_printf(2, "Error\n");
	exit(ERROR);
}

char	*ft_one_line(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 1;
	str = NULL;
	while (i < argc)
	{
		str = ft_strjoin_free(str, argv[i]);
		str = ft_strjoin_free(str, " ");
		i++;
	}
	return (str);
}

char	*ft_strjoin_free(char *dest, char *src)
{
	int		d_len;
	int		s_len;
	char	*res;
	int		i;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	res = malloc(sizeof(char) * (s_len + d_len + 1));
	if (!res)
	{
		ft_printf(2, "Error\n");
		free(dest);
		exit (ERROR);
	}
	i = -1;
	while (++i < d_len)
		res[i] = dest[i];
	i = -1;
	while (++i < s_len)
		res[i + d_len] = src[i];
	res[i + d_len] = '\0';
	free (dest);
	return (res);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
		len++;
	return (len);
}

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
