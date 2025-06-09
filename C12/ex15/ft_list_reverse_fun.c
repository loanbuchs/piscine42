/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:06:49 by loan              #+#    #+#             */
/*   Updated: 2025/06/02 22:29:02 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}

void	swap(void **a, void **b)
{
	void	**tmp;

	*tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size_list;
	int		i;
	int		j;
	t_list	*current;
	t_list	*to_swap;

	i = 0;
	size_list = ft_list_size(begin_list);
	current = begin_list;
	while (i < (size_list / 2))
	{
		to_swap = begin_list;
		j = 0;
		while (j < (size_list - i - 1))
		{
			to_swap = to_swap->next;
			j++;
		}
		swap(&to_swap->data, &current->data);
		i++;
		current = current->next;
	}
}
