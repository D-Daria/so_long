/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:40:42 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/11 16:21:51 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_ptr(unsigned long ptr)
{
	int	count_ptr;

	count_ptr = 0;
	if (ptr == 0)
		return (count_ptr += 1);
	while (ptr != 0)
	{
		count_ptr += 1;
		ptr /= 16;
	}
	return (count_ptr);
}

void	ft_putptr(unsigned long ptr)
{
	unsigned long	rem;

	if (ptr > 0)
	{
		rem = ptr % 16;
		ft_putptr(ptr / 16);
		if (rem < 10)
			ft_putchar(rem + '0');
		else
			ft_putchar(rem + '7' + 32);
	}
}

int	ft_putptr_num(void *ptr)
{
	unsigned long	converted_ptr;
	int				num_printed;

	converted_ptr = (unsigned long long)ptr;
	num_printed = 0;
	if (ptr == 0)
		num_printed += ft_putstr_num("0x0");
	else
	{
		num_printed += ft_count_ptr(converted_ptr) + ft_putstr_num("0x");
		ft_putptr(converted_ptr);
	}
	return (num_printed);
}
