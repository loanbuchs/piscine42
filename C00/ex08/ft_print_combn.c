/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:00:18 by marvin            #+#    #+#             */
/*   Updated: 2024/11/01 10:00:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_nb(int nb)
{
	int	asciiset;

	asciiset = '0' + nb;
	write(1, &asciiset, 1);
}

int	max_number(int n)
{
	int	i;
	int	maxnb;

	maxnb = 1;
	i = 0;
	while (i < n)
	{
		maxnb = maxnb * 10;
		i++;
	}
	return (maxnb);
}

int	iscroissant(int combn, int n)
{
	int	croissant;
	int	a;
	int	b;

	croissant = 0;
	a = 0;
	b = 10;
	while (a < n)
	{
		if (combn % 10 < b)
		{
			croissant = 1;
			b = combn % 10;
			combn = combn / 10;
		}
		else
		{
			croissant = 0;
			return (croissant);
		}
		a++;
	}
	return (croissant);
}

void	write_comb(int combn, int n)
{
	int	number;
	int	divided_number;

	if (combn > 9)
	{
		number = combn % 10;
		divided_number = combn / 10;
		n--;
		write_comb(divided_number, n);
	}
	if (combn > 9)
		write_nb(number);
	else
	{
		n--;
		if (n != 0)
			write_nb(0);
		write_nb(combn);
	}
}

void	ft_print_combn(int n)
{
	int	limit;
	int	combn;
	int	croissant;
	int	a;

	a = 0;
	combn = 0;
	limit = max_number(n);
	while (combn < limit)
	{
		croissant = 0;
		croissant = iscroissant(combn, n);
		if (croissant != 0)
		{
			if (a != 0)
				write(1, ", ", 2);
			write_comb(combn, n);
			a++;
		}
		combn++;
	}
}
