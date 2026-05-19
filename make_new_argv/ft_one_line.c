/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:44:42 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/16 21:35:28 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_printf("%s", "Error");
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
