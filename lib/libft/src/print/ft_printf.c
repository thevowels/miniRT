/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 22:26:05 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/08/27 11:25:15 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

/*
	flag:
	1	base 10
	2	base 16 Lower case
	3	base 16 Upper case
*/
int	ft_fpf_printbase(int base, int upper, long nb)
{
	char	*str_base[2];
	int		length;

	str_base[0] = "0123456789abcdef";
	str_base[1] = "0123456789ABCDEF";
	length = 0;
	if (upper == 'u')
		base = 10;
	if (upper == 'X')
		upper = 1;
	else if (upper == 'x' || upper == 'u')
		upper = 0;
	if (nb < 0)
	{
		nb *= -1;
		length += write(1, "-", 1);
	}
	if (nb < base)
		length += write(1, &str_base[upper][nb], 1);
	if (nb >= base)
	{
		length += ft_fpf_printbase(base, upper, (nb / base));
		length += write(1, &str_base[upper][nb % base], 1);
	}
	return (length);
}

static int	ft_fpf_printstr(char *str)
{
	int	i;

	if (!str)
		return (ft_fpf_printstr("(null)"));
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

void	ft_formats(va_list args, const char *f, int *length,
		unsigned long long ptr)
{
	if (*f == 's')
		(*length) += ft_fpf_printstr(va_arg(args, char *));
	else if (*f == 'd' || *f == 'i')
		(*length) += ft_fpf_printbase(10, 0, va_arg(args, int));
	else if (*f == 'u' || *f == 'x' || *f == 'X')
		(*length) += ft_fpf_printbase(16, *f, va_arg(args, unsigned int));
	else if (*f == 'p')
	{
		ptr = va_arg(args, unsigned long long);
		if (!ptr)
			(*length) += ft_fpf_printstr("(nil)");
		else
		{
			(*length) += ft_fpf_printstr("0x");
			if (ptr >= 16)
			{
				(*length) += ft_fpf_printbase(16, 'x', ptr / 16);
				ptr = ptr % 16;
			}
			(*length) += ft_fpf_printbase(16, 'x', ptr);
		}
	}
	else
		(*length) += write(1, (f - 1), (1 + (*f != '%' && *f != 0)));
}

int	ft_printf(const char *str, ...)
{
	va_list				args;
	int					length;
	unsigned long long	ptr;

	length = 0;
	va_start(args, str);
	while (str && *str)
	{
		ptr = 0;
		if (*str == '%')
		{
			if (*(++str) == 'c')
			{
				ptr = va_arg(args, int);
				length += write(1, &ptr, 1);
			}
			else
				ft_formats(args, str, &length, ptr);
		}
		else
			length += write(1, str, 1);
		(void)(*str && str++);
	}
	va_end(args);
	return (length);
}
