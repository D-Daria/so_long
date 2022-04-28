/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:39:50 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/11 16:20:02 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_hex(unsigned int x)
{
	int	count_hex;

	count_hex = 0;
	if (x == 0)
		return (count_hex += 1);
	while (x != 0)
	{
		count_hex += 1;
		x /= 16;
	}
	return (count_hex);
}

void	ft_puthex_low(unsigned int x)
{
	int	rem;

	if (x > 0)
	{
		rem = x % 16;
		ft_puthex_low(x / 16);
		if (rem < 10)
			ft_putchar(rem + '0');
		else
			ft_putchar(rem + '7' + 32);
	}
}

void	ft_puthex_up(unsigned int x)
{
	int	rem;

	if (x > 0)
	{
		rem = x % 16;
		ft_puthex_up(x / 16);
		if (rem < 10)
			ft_putchar(rem + '0');
		else
			ft_putchar(rem + '7');
	}
}

int	ft_puthex_num(unsigned int x, char conv)
{
	int	num_printed;

	num_printed = 0;
	if (x == 0)
	{
		num_printed += ft_putchar_num('0');
		return (num_printed);
	}
	num_printed = ft_count_hex(x);
	if (conv == 'x')
		ft_puthex_low(x);
	else if (conv == 'X')
		ft_puthex_up(x);
	return (num_printed);
}
