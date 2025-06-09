/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 23:51:54 by loan              #+#    #+#             */
/*   Updated: 2025/05/29 00:10:44 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*node;
	t_list	*lastnode;

	while (size)
	{
		node = ft_create_elem(strs[size]);
		node->next = lastnode;
		lastnode = node;
		size--;
	}
	return (lastnode);
}
