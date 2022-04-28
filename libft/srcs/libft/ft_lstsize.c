/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:10:51 by mrhyhorn          #+#    #+#             */
/*   Updated: 2021/10/19 13:11:48 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp_begin;
	int		count;

	count = 0;
	temp_begin = lst;
	while (temp_begin != NULL)
	{
		count++;
		temp_begin = temp_begin->next;
	}
	return (count);
}
