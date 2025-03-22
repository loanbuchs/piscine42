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

void	print_hex(long value)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (value > 15)
	{
		print_hex(value / 16);
		print_hex(value % 16);
	}
	else
		write(1, &hex[value], 1);
}

void	print_info(char *addr, unsigned int location)
{
	long	toprint;
	long	value;

	if (!(location % 16))
	{
		if (location)
			write(1, "\n", 1);
		toprint = (long)addr + location;
		print_hex(toprint);
		write(1, ":", 1);
	}
	value = addr[location];
	if (value < 16)
		write(1, "0", 1);
	print_hex(value);
	if (location % 2)
		write(1, " ", 1);
}

void	print_str(char *addr, int location, char *toprint)
{
	int	i;

	if (location && !(location % 16))
	{
		i = 0;
		while (i < 16)
		{
			if (toprint[i] <= 31 || toprint[i] > 126)
				write(1, ".", 1);
			else
				write(1, &toprint[i], 1);
			i++;
		}
	}
	toprint[location % 16] = addr[location];
}

void	print_end(int location, char *toprint)
{
	int	i;

	i = 0;
	while ((location + i) % 16)
	{
		write(1, " ", 1);
		i++;
	}
	i = 0;
	while (i - location % 16)
	{
		if (toprint[i] <= 31 || toprint[i] > 126)
			write(1, ".", 1);
		else
			write(1, &toprint[i], 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*ptr;
	char			toprint[16];

	ptr = addr;
	i = 0;
	while (i < size)
	{
		print_str(ptr, i, toprint);
		print_info(ptr, i);
		i++;
	}
	print_end(i, toprint);
	return (addr);
}
