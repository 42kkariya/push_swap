/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 05:10:05 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/29 16:00:09 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

char	*checker_ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*checker_gnl_free_all(t_gnl gnl)
{
	free(gnl.buf);
	free(gnl.res);
	return (NULL);
}

int	checker_ft_strjoin_free(t_gnl *gnl)
{
	int		i;
	int		r_len;
	int		b_len;
	char	*old;

	i = -1;
	r_len = checker_ft_strlen(gnl->res);
	b_len = checker_ft_strlen(gnl->buf);
	old = gnl->res;
	gnl->res = malloc(sizeof(char) * (r_len + b_len + 1));
	if (!gnl->res)
	{
		free (old);
		return (FALSE);
	}
	while (++i < r_len)
		gnl->res[i] = old[i];
	i = -1;
	while (++i < b_len)
		gnl->res[r_len + i] = gnl->buf[i];
	gnl->res[r_len + i] = '\0';
	free(old);
	return (TRUE);
}

int	checker_ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*checker_ft_strdup(char *src)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = checker_ft_strlen(src);
	if (!src)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
