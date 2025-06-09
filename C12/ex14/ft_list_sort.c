/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:31:58 by loan              #+#    #+#             */
/*   Updated: 2025/06/02 23:11:45 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	void	*tmp;
	int		sorted;

	if (!begin_list || !*begin_list)
		return ;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		current = *begin_list;
		while (current->next)
		{
			if (cmp(current->next->data, current->data))
			{
				tmp = current->data;
				current->data = current->next->data;
				current->next->data = tmp;
				sorted = 0;
			}
			current = current->next;
		}
	}
}
