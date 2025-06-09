/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:45:16 by loan              #+#    #+#             */
/*   Updated: 2025/05/28 18:58:25 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_last(t_list *beginlist)
{
	t_list	*last_node;

	while (beginlist)
	{
		last_node = beginlist;
		beginlist = beginlist->next;
	}
	return (last_node);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*newnode;
	t_list	*lastnode;

	newnode = ft_create_elem(data);
	lastnode = ft_list_last(*begin_list);
	lastnode->next = newnode;
	newnode->next = NULL;
}
