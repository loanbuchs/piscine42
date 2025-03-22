/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:34:48 by marvin            #+#    #+#             */
/*   Updated: 2024/10/29 10:34:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int		length_nb(int nb, int maxlength);
int		absolute_value(int nb);
int		power(int nb, int exp);
void	write_nb(int nb, int lengthnb);

void	ft_putnbr(int nb)
{
	int	lengthnb;

	if (nb < 0)
		write(1, "-", 1);
	nb = absolute_value(nb);
	lengthnb = length_nb(nb, 9);
	write_nb(nb, lengthnb);
}

int	length_nb(int nb, int maxlength)
{
	int	divider;
	int	count;
	int	length;

	divider = 1;
	length = 0;
	count = 0;
	while (maxlength >= 0)
	{
		if (nb / divider != 0)
		{
			length = length + count;
			length++;
			count = 0;
		}
		else
			count++;
		divider = divider * 10;
		maxlength--;
	}
	return (length);
}

int	absolute_value(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

void	write_nb(int nb, int lengthnb)
{
	int	asciiset;
	int	divider;

	if (lengthnb != 0)
	{
		divider = power (10, (lengthnb - 1));
		asciiset = '0' + (nb / divider);
		nb = nb % divider;
		write (1, &asciiset, 1);
		lengthnb--;
		write_nb(nb, lengthnb);
	}
}

int	power(int nb, int exp)
{
	int	result;

	result = 1;
	while (exp != 0)
	{
		result = result * nb;
		exp--;
	}
	return (result);
}
