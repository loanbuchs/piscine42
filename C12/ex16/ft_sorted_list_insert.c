/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:29:33 by loan              #+#    #+#             */
/*   Updated: 2025/06/02 23:14:10 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current_node;
	t_list	*last_node;
	t_list	*new_node;

	new_node = ft_create_elem(data);
	current_node = *begin_list;
	while (cmp(current_node->data, data) && current_node->next)
	{
		last_node = current_node;
		current_node = current_node->next;
	}
	last_node->next = new_node;
	new_node->next = current_node;
}
