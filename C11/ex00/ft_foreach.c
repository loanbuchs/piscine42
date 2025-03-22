/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:47:16 by loan              #+#    #+#             */
/*   Updated: 2025/03/22 18:10:24 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f) (int))
{
	int	save;

	save = length;
	while (length != 0)
	{
		f(tab[save - length]);
		length--;
	}
}

/*#include <unistd.h>
#include <stdlib.h>
void	write_nb(int nb)
{
	int	asciiset;
		asciiset = '0' + nb;
		write (1, &asciiset, 1);
}

int main()
{
	int tab [] = {1,2,3,4,5,6,7,8,9};
	ft_foreach(tab, 9, &write_nb);
	return 0;
}
*/