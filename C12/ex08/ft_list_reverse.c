/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:52:55 by loan              #+#    #+#             */
/*   Updated: 2025/05/29 16:24:44 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*last_node;
	t_list	*next_node;

	last_node = NULL;
	while (*begin_list)
	{
		next_node = (*begin_list)->next;
		(*begin_list)->next = last_node;
		last_node = *begin_list;
		*begin_list = next_node;
	}
	*begin_list = last_node;
}
