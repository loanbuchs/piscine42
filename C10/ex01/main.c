/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:29:10 by loan              #+#    #+#             */
/*   Updated: 2025/04/27 23:02:13 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int	ft_display_file(char *file_name)
{
	int		file;
	int		reading;
	char	filecontent;

	file = open(file_name, 0);
	if (file == -1)
		return (0);
	reading = read(file, &filecontent, 1);
	while (reading)
	{
		if (reading == -1)
			return (0);
		write(1, &filecontent, 1);
		reading = read(file, &filecontent, 1);
	}
	close(file);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		a;
	char	buffer[30000];

	while (argc == 1)
	{
		a = read(0, buffer, 29999);
		write(1, buffer, a);
	}
	i = 1;
	while (i < argc)
	{
		a = ft_display_file(argv[i]);
		if (a == 0)
		{
			write(1, "ft_cat: ", 8);
			write(1, argv[i], ft_strlen(argv[i]));
			write(1, ": ", 2);
			write(1, strerror(errno), ft_strlen(strerror(errno)));
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}
