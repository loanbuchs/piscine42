/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:46:39 by loan              #+#    #+#             */
/*   Updated: 2025/05/28 00:29:37 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	add(int value1, int value2)
{
	int	toprint[10];
	int	i;

	i = 0;
	value1 += value2;
	while (value1)
	{
		toprint[i] = value1 % 10 + '0';
		value1 /= 10;
		i++;
	}
	i--;
	while (i != -1)
	{
		write(1, &toprint[i], 1);
		i--;
	}
}

void	sub(int value1, int value2)
{
	int	toprint[10];
	int	i;
	int	isneg;

	i = 0;
	isneg = 0;
	value1 -= value2;
	if (value1 < 0 && isneg++)
		isneg++;
	value1 = -value1;
	while (value1)
	{
		toprint[i] = value1 % 10 + '0';
		value1 /= 10;
		i++;
	}
	i--;
	if (isneg)
		write(1, "-", 1);
	while (i != -1)
	{
		write(1, &toprint[i], 1);
		i--;
	}
}

void	mult(int value1, int value2)
{
	int	toprint[10];
	int	i;
	int	isneg;

	i = 0;
	isneg = 0;
	value1 *= value2;
	if (value1 < 0)
	{
		isneg++;
		value1 = -value1;
	}
	while (value1)
	{
		toprint[i] = value1 % 10 + '0';
		value1 /= 10;
		i++;
	}
	if (isneg)
		write(1, "-", 1);
	while (i-- != -1)
		write(1, &toprint[i], 1);
}

void	div(int value1, int value2)
{
	int	toprint[10];
	int	i;
	int	isneg;

	i = 0;
	isneg = 0;
	if (!value2)
	{
		write(1, "Stop : division by zero", 23);
		return ;
	}
	value1 /= value2;
	if (value1 < 0 && isneg++)
		value1 = -value1;
	while (value1)
	{
		toprint[i] = value1 % 10 + '0';
		value1 /= 10;
		i++;
	}
	if (isneg)
		write(1, "-", 1);
	while (i-- != -1)
		write(1, &toprint[i], 1);
}

void	modulo(int value1, int value2)
{
	int	toprint[10];
	int	i;
	int	isneg;

	i = 0;
	isneg = 0;
	if (!value2)
	{
		write(1, "Stop : modulo by zero", 21);
		return ;
	}
	value1 /= value2;
	if (value1 < 0 && isneg++)
		value1 = -value1;
	while (value1)
	{
		toprint[i] = value1 % 10 + '0';
		value1 /= 10;
		i++;
	}
	if (isneg)
		write(1, "-", 1);
	while (i-- != -1)
		write(1, &toprint[i], 1);
}
