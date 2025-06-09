/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 23:14:43 by loan              #+#    #+#             */
/*   Updated: 2025/06/03 00:08:32 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	t_list	*current_node;
	t_list	*current_node2;
	t_list	*last_node;
	t_list	*to_insert;

	current_node = *begin_list1;
	current_node2 = begin_list2;
	last_node = NULL;
	while (current_node2)
	{
		while (current_node && cmp(current_node->data, current_node2->data))
		{
			last_node = current_node;
			current_node = current_node->next;
		}
		to_insert = current_node2;
		current_node2 = current_node2->next;
		if (last_node == NULL)
			*begin_list1 = to_insert;
		else
			last_node->next = to_insert;
		last_node = to_insert;
		to_insert->next = current_node;
	}
}
