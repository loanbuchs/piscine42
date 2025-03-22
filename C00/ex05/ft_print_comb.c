/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:17:56 by marvin            #+#    #+#             */
/*   Updated: 2024/10/26 12:17:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		splithundred(int number);
int		splitten(int number, int unit);
int		splitunit(int number);
void	writenumber(int unit, int ten, int hundred, int number);

void	ft_print_comb(void)
{
	int	number;
	int	unit;
	int	ten;
	int	hundred;

	number = 0;
	while (number < 1000)
	{
		unit = splitunit(number);
		ten = splitten(number, unit);
		hundred = splithundred(number);
		if (unit != ten && ten != hundred && unit != hundred)
		{
			if (unit > ten && ten > hundred)
			{
				writenumber(unit, ten, hundred, number);
			}
		}
		number++;
	}
}

int	splithundred(int number)
{
	int	hundred;

	hundred = number / 100;
	return (hundred);
}

int	splitten(int number, int unit)
{
	int	ten;

	ten = (number % 100 - unit) / 10;
	return (ten);
}

int	splitunit(int number)
{
	int	unit;

	unit = number % 10;
	return (unit);
}

void	writenumber(int unit, int ten, int hundred, int number)
{
	int	asciiset;

	if (number > 12)
	{
		asciiset = ',';
		write (1, &asciiset, 1);
		asciiset = ' ';
		write(1, &asciiset, 1);
	}
	asciiset = '0' + hundred;
	write (1, &asciiset, 1);
	asciiset = '0' + ten;
	write (1, &asciiset, 1);
	asciiset = '0' + unit;
	write (1, &asciiset, 1);
}
