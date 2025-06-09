/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:14:44 by marvin            #+#    #+#             */
/*   Updated: 2024/11/15 12:14:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	swap(int *a, int *b)
{
	int	save;

	save = *a;
	*a = *b;
	*b = save;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
			swap(&tab[i], &tab[i + 1]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (tab[i] <= tab[i + 1])
			i++;
		else
			ft_sort_int_tab(tab, size);
	}
}
