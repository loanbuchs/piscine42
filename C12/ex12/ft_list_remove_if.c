/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:15:46 by loan              #+#    #+#             */
/*   Updated: 2025/05/29 18:32:27 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*last_node;
	t_list	*current_node;
	t_list	*tmp;

	current_node = *begin_list;
	last_node = NULL;
	while (current_node)
	{
		if (!cmp(current_node->data, data_ref))
		{
			if (last_node)
				last_node->next = current_node->next;
			else
				*begin_list = current_node->next;
			tmp = current_node->next;
			free_fct(current_node->data);
			free(current_node);
			current_node = tmp;
		}
		else
		{
			last_node = current_node;
			current_node = current_node->next;
		}
	}
}
