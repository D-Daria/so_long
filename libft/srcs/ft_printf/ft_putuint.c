/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:41:22 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/11 16:22:29 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_uint(unsigned int uint)
{
	int	count;

	count = 0;
	if (uint == 0)
		count += 1;
	while (uint > 0)
	{
		count += 1;
		uint /= 10;
	}
	return (count);
}

void	ft_putuint(unsigned int uint)
{
	if (uint >= 10)
	{
		ft_putuint((uint / 10));
		ft_putuint((uint % 10));
	}
	else
		ft_putchar(uint + '0');
}

int	ft_putuint_num(unsigned int uint)
{
	int	num_printed;

	num_printed = ft_count_uint(uint);
	ft_putuint(uint);
	return (num_printed);
}
