/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:40:02 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/01/20 19:08:15 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp_begin;
	int		count;

	count = 0;
	temp_begin = lst;
	if (temp_begin == NULL)
		return (NULL);
	while (temp_begin->next != NULL)
		temp_begin = temp_begin->next;
	return (temp_begin);
}
