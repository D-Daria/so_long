/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:39:57 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/11 16:17:57 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_num(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count += 1;
	}
	else if (nbr == 0)
		count += 1;
	while (nbr > 0)
	{
		count += 1;
		nbr /= 10;
	}
	return (count);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		nbr *= (-1);
		ft_putchar('-');
	}
	if (nbr >= 10)
	{
		ft_putnbr((nbr / 10));
		ft_putnbr((nbr % 10));
	}
	else
		ft_putchar(nbr + '0');
}

int	ft_putnbr_num(int nbr)
{
	int	num_printed;

	num_printed = 0;
	if (nbr == -2147483648)
	{
		num_printed += ft_putstr_num("-2147483648");
		return (num_printed);
	}
	num_printed = num_printed + ft_count_num(nbr);
	ft_putnbr(nbr);
	return (num_printed);
}
