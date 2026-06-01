/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:48:26 by mtaisei           #+#    #+#             */
/*   Updated: 2026/05/29 16:09:31 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

char	*checker_free_save_all(t_gnl gnl, char **save)
{
	*save = NULL;
	return (checker_gnl_free_all(gnl));
}

char	*checker_get_next_line(int fd)
{
	static char	*save;
	t_gnl		gnl;
	int			check;

	gnl.buf = NULL;
	gnl.line = NULL;
	gnl.res = save;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	check = checker_read_and_save(fd, &gnl);
	if (check == FALSE)
		return (checker_free_save_all(gnl, &save));
	check = checker_my_get_line(&gnl);
	if (check == FALSE)
		return (checker_free_save_all(gnl, &save));
	check = checker_updeta_save(&gnl, &save);
	if (check == FALSE)
		return (checker_free_save_all(gnl, &save));
	checker_gnl_free_all(gnl);
	return (gnl.line);
}

int	checker_updeta_save(t_gnl *gnl, char **save)
{
	char	*newline;

	newline = checker_ft_strchr(gnl->res, '\n');
	*save = NULL;
	if (!newline || !newline[1])
		return (TRUE);
	*save = checker_ft_strdup(newline + 1);
	if (!*save)
		return (FALSE);
	return (TRUE);
}

int	checker_read_and_save(int fd, t_gnl *gnl)
{
	int		nb;
	int		check;

	gnl->buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!gnl->buf)
		return (FALSE);
	while (!checker_ft_strchr(gnl->res, '\n'))
	{
		nb = read(fd, gnl->buf, BUFFER_SIZE);
		if (nb == 0)
			break ;
		if (nb < 0)
			return (FALSE);
		gnl->buf[nb] = '\0';
		check = checker_ft_strjoin_free(gnl);
		if (check == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

int	checker_my_get_line(t_gnl *gnl)
{
	int		len;
	int		i;

	len = 0;
	if (!gnl->res || !gnl->res[0])
		return (FALSE);
	while (gnl->res[len] != '\n' && gnl->res[len] != '\0')
		len++;
	if (gnl->res[len] == '\n')
		len++;
	gnl->line = malloc(sizeof(char) * (len + 1));
	if (!gnl->line)
		return (FALSE);
	i = 0;
	while (i < len)
	{
		gnl->line[i] = gnl->res[i];
		i++;
	}
	gnl->line[i] = '\0';
	return (TRUE);
}
