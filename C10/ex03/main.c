/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:26:49 by loan              #+#    #+#             */
/*   Updated: 2025/05/25 23:58:30 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <hex.h>

void	ft_print_str(unsigned char *str, int tab)
{
	int	i;

	if (tab > 24)
		write(1, " ", 1);
	tab++;
	while (tab--)
		write(1, " ", 1);
	i = 0;
	write(1, " ", 1);
	write(1, "|", 1);
	while (str[i] || i == 0)
	{
		if (str[i] < 32 || str[i] > 126)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "|", 1);
	write(1, "\n", 1);
}

void	ft_hexdump(unsigned char *str, int tab, long int addr)
{
	int	i;

	if (addr % 16)
		write_hexaddr(addr - addr % 16);
	else
		write_hexaddr(addr - 16);
	if (addr % 16)
		str[addr % 16] = 0;
	write(1, "  ", 2);
	i = 0;
	while (str[i] || i == 0)
	{
		if ((str[i] < 16 && str[i]) || (!str[i]))
			write(1, "0", 1);
		print_hex(str[i]);
		if (i == 7)
			write(1, " ", 1);
		write(1, " ", 1);
		i++;
	}
	i = 0;
	ft_print_str(str, tab);
	if (addr % 16)
		write_hexaddr(addr);
}

void	standard_input(void)
{
	unsigned char	content[17];
	long int		addr;
	unsigned char	buffer;

	addr = 0;
	while (read(0, &buffer, 1) > 0)
	{
		content[addr % 16] = buffer;
		addr++;
		if (!(addr % 16))
			ft_hexdump(content, 0, addr);
	}
	if (addr % 16)
		ft_hexdump(content, 3 * (16 - (addr % 16)), addr);
	return ;
}

int	main(int argc, char const *argv[])
{
	char				buffer;
	int					i;
	int					fd;
	long int			addr;
	unsigned char		content[17];

	content[16] = 0;
	addr = -1;
	i = 0;
	if (argc == 1)
		standard_input();
	while (i++ < argc)
	{
		fd = open(argv[i], 0);
		while (read(fd, &buffer, 1) > 0 && (addr++ != -2))
		{
			if (!(addr % 16) && addr)
				ft_hexdump(content, 0, addr);
			content[addr % 16] = buffer;
		}
		close(fd);
	}
	if (addr % 16)
		ft_hexdump(content, 3 * (16 - ((addr + 1) % 16)), addr + 1);
	return (0);
}
