/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:49:15 by lchew             #+#    #+#             */
/*   Updated: 2023/02/28 14:10:37 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*specifier(const char c, va_list arg);
static int	charcount(const char c, const char *res, int count);
static char	*print_cap(const char c, va_list arg, char *res);

int	ft_printf(const char *str, ...)
{
	va_list			arg;
	char			*res;
	static int		count;

	count = 0;
	va_start(arg, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			res = specifier(*(++str), arg);
			count = charcount(*str, res, count);
			ft_putstr_fd(res, 1);
			if (*str != 's')
				free(res);
		}
		else
		{
			++count;
			ft_putchar_fd(*str, 1);
		}
		++str;
	}
	va_end(arg);
	return (count);
}

static char	*specifier(const char c, va_list arg)
{
	char	*res;

	res = NULL;
	if (c == 'c' || c == 'p' || c == '%')
		res = print_cap(c, arg, res);
	else if (c == 's')
		res = va_arg(arg, char *);
	else if (c == 'd')
		res = ft_itoa_base(va_arg(arg, int), BASE_DEC, BASE_DEC_C);
	else if (c == 'i')
		res = ft_itoa_base(va_arg(arg, int), BASE_DEC, BASE_DEC_C);
	else if (c == 'u')
		res = ft_itoa_base(va_arg(arg, unsigned int), BASE_DEC, BASE_DEC_C);
	else if (c == 'x')
		res = ft_itoa_base(va_arg(arg, unsigned int), BASE_HEX, BASE_HEX_CL);
	else if (c == 'X')
		res = ft_itoa_base(va_arg(arg, unsigned int), BASE_HEX, BASE_HEX_CU);
	return (res);
}

static int	charcount(const char c, const char *res, int count)
{
	if (c == 'c' && *res == '\0')
		count += write(1, "\0", 1);
	else if (c == 's' && res == NULL)
		count += write(1, "(null)", 6);
	else
		count += ft_strlen(res);
	return (count);
}

static char	*print_cap(const char c, va_list arg, char *res)
{
	char	*tmp;

	if (c == 'c')
	{
		res = ft_calloc(2, sizeof(char));
		*res = va_arg(arg, int);
	}
	else if (c == 'p')
	{
		tmp = ft_itoa_u(va_arg(arg, long), BASE_HEX, BASE_HEX_CL);
		res = ft_strjoin(PTR_INIT_L, tmp);
		free(tmp);
	}
	else if (c == '%')
	{
		res = ft_calloc(2, sizeof(char));
		*res = c;
	}
	return (res);
}
