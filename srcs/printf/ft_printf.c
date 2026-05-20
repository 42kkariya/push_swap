/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaisei <mtaisei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:24:45 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/16 13:21:05 by mtaisei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_format_print(char c, va_list *a, int fd)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*a, int), fd));
	else if (c == 's')
		return (ft_print_str(va_arg(*a, char *), fd));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(*a, void *), fd));
	else if (c == 'd')
		return (ft_print_nbr(va_arg(*a, int), fd));
	else if (c == 'i')
		return (ft_print_nbr(va_arg(*a, int), fd));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(*a, unsigned int), fd));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(*a, unsigned int), c, fd));
	else if (c == '%')
		return (ft_print_char('%', fd));
	else if (c == 'f')
		return (ft_print_double(va_arg(*a, double), fd));
	return (-1);
}

static int	ft_print_fmt_char(const char *fmt, int *i, va_list *a, int fd)
{
	int	ret;

	if (fmt[*i] == '%')
	{
		if (fmt[*i + 1] == '\0')
		{
			(*i)++;
			return (-1);
		}
		ret = check_format_print(fmt[*i + 1], a, fd);
		*i += 2;
	}
	else
	{
		ret = ft_print_char(fmt[*i], fd);
		(*i)++;
	}
	return (ret);
}

int	ft_printf(int fd, const char *format, ...)
{
	int		i;
	int		count;
	int		ret;
	va_list	a;

	if (!format)
		return (-1);
	va_start(a, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		ret = ft_print_fmt_char(format, &i, &a, fd);
		if (ret == -1)
		{
			va_end(a);
			return (-1);
		}
		count += ret;
	}
	va_end(a);
	return (count);
}
