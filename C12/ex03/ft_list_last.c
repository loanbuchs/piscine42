/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:34:29 by loan              #+#    #+#             */
/*   Updated: 2025/05/28 18:44:52 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
