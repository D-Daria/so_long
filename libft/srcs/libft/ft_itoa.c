/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:57:16 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/06 16:51:25 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check_negative(int n)
{
	int	is_negative;

	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	else
		is_negative = 0;
	return (is_negative);
}

static int	ft_count_digits(int num_param)
{
	int	count_digits;

	count_digits = 1;
	if (num_param <= 0)
	{
		num_param *= (-1);
		count_digits += 1;
	}
	while (num_param > 0)
	{
		count_digits++;
		num_param /= 10;
	}
	return (count_digits);
}

static char	*ft_fill_arr(char *num_str, int count_digits, int n)
{
	char	mod;

	while (count_digits > 0)
	{
		mod = n % 10 + '0';
		num_str[count_digits] = mod;
		count_digits--;
		n /= 10;
	}
	num_str[count_digits] = ((n % 10) + '0');
	return (num_str);
}

char	*ft_itoa(int n)
{
	char	*num_str;
	int		count_digits;
	int		is_negative;

	is_negative = ft_check_negative(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count_digits = ft_count_digits(n);
	if (is_negative)
		n *= (-1);
	num_str = (char *)malloc(sizeof(char) * (count_digits + 1));
	if (num_str == NULL)
		return (NULL);
	count_digits -= 1;
	num_str[count_digits] = '\0';
	if (n == 0)
	{
		num_str[0] = '0';
		return (num_str);
	}
	num_str = ft_fill_arr(num_str, count_digits - 1, n);
	if (is_negative)
		num_str[0] = '-';
	return (num_str);
}
