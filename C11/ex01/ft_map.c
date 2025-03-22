/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:11:02 by loan              #+#    #+#             */
/*   Updated: 2025/03/22 18:29:06 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_map(int *tab, int length, int (*f) (int))
{
	int	save;

	save = length;
	while (length != 0)
	{
		tab[save - length] = f(tab[save - length]);
		length--;
	}
	return (tab);
}
