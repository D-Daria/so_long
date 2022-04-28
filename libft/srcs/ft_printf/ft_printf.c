/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:39:00 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/11 16:19:13 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_define_conv(char conv, va_list argp)
{
	int	num_printed;

	num_printed = 0;
	if (conv == 'c')
		num_printed += ft_putchar_num(va_arg(argp, int));
	else if (conv == 's')
		num_printed += ft_putstr_num(va_arg(argp, char *));
	else if (conv == 'p')
		num_printed += ft_putptr_num(va_arg(argp, void *));
	else if (conv == 'd' || conv == 'i')
		num_printed += ft_putnbr_num(va_arg(argp, int));
	else if (conv == 'u')
		num_printed += ft_putuint_num(va_arg(argp, unsigned int));
	else if (conv == 'x' || conv == 'X')
		num_printed += ft_puthex_num(va_arg(argp, unsigned int), conv);
	else if (conv == '%')
		num_printed += ft_putchar_num('%');
	return (num_printed);
}

int	ft_parse_str(const char *format_str, va_list argp)
{
	int	num_printed;
	int	i;

	num_printed = 0;
	i = 0;
	while (format_str[i] != '\0')
	{
		if (format_str[i] != '%' && format_str[i] != '\0')
			num_printed += ft_putchar_num(format_str[i]);
		else
		{
			i++;
			num_printed += ft_define_conv(format_str[i], argp);
		}
		i++;
	}
	return (num_printed);
}

int	ft_printf(const char *format_str, ...)
{
	int		num_printed;
	va_list	argp;

	num_printed = 0;
	va_start(argp, format_str);
	num_printed = ft_parse_str(format_str, argp);
	va_end(argp);
	return (num_printed);
}
