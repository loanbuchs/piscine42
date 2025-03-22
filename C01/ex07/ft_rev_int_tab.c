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

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	intermediate;

	i = 0;
	size = size - 1;
	while (i < size / 2)
	{
		intermediate = tab[size - i];
		tab[size - i] = tab[i];
		tab[i] = intermediate;
		i++;
	}
	i = 0;
	while (i <= size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}
