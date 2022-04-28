/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:40:45 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/01/20 19:08:05 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;

	current = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_list = ft_lstnew(f(lst->content));
		if (new_list == NULL)
		{
			del(current->content);
			free(current);
			return (NULL);
		}
		ft_lstadd_back(&current, new_list);
		lst = lst->next;
	}
	return (current);
}
