/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:39:19 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/11 16:19:33 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putchar_num(int c)
{
	char	ch;
	int		num_printed;

	ch = (char)c;
	num_printed = write(1, &ch, 1);
	return (num_printed);
}
