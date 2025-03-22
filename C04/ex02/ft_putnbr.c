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
#include <unistd.h>

void	putpositive(int nb, int *towrite)
{
	int	i;

	i = 0;
	*(towrite + i) = 0;
	i++;
	while (nb)
	{
		*(towrite + i) = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	i--;
	while (*(towrite + i))
	{
		write(1, &*(towrite + i), 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	int	towrite[12];

	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	putpositive(nb, towrite);
}
