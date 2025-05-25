/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:46:39 by loan              #+#    #+#             */
/*   Updated: 2025/05/25 22:52:26 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(int value)
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

void	write_hexaddr(long int addr)
{
	if (addr == 0)
	{
		write(1, "00000000", 8);
		return ;
	}
	else if (addr < 16)
		write(1, "0000000", 7);
	else if (addr < 256)
		write(1, "000000", 6);
	else if (addr < 4096)
		write(1, "00000", 5);
	else if (addr < 65536)
		write(1, "0000", 4);
	else if (addr < 1048576)
		write(1, "000", 3);
	else if (addr < 16777216)
		write(1, "00", 2);
	else if (addr < 268435456)
		write(1, "0", 1);
	print_hex(addr);
}
