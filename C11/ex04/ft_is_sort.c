/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:35:39 by loan              #+#    #+#             */
/*   Updated: 2025/05/26 14:03:21 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	save;

	save = length;
	while (length - 1)
	{
		if (f(tab[save - length], tab[save - length + 1]) >= 0)
			length--;
		else
			return (0);
	}
	return (1);
}
