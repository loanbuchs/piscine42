/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:50:58 by marvin            #+#    #+#             */
/*   Updated: 2024/10/26 15:50:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	writenumbers(int number1, int number2);

void	ft_print_comb2(void)
{
	int	number1;
	int	number2;

	number1 = 0;
	while (number1 < 100)
	{
		number2 = 0;
		while (number2 < 100)
		{
			if (number1 < number2)
			{
				if (number2 > 1)
				{
					write (1, ", ", 2);
				}
				writenumbers(number1, number2);
			}
			number2++;
		}
		number1++;
	}
}

void	writenumbers(int number1, int number2)
{
	int	asciiset;
	int	unit1;
	int	unit2;
	int	ten1;
	int	ten2;

	unit1 = number1 % 10;
	unit2 = number2 % 10;
	ten1 = number1 / 10;
	ten2 = number2 / 10;
	asciiset = '0' + ten1;
	write (1, &asciiset, 1);
	asciiset = '0' + unit1;
	write (1, &asciiset, 1);
	write (1, " ", 1);
	asciiset = '0' + ten2;
	write (1, &asciiset, 1);
	asciiset = '0' + unit2;
	write (1, &asciiset, 1);
}
