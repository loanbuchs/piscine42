/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:48:55 by loan              #+#    #+#             */
/*   Updated: 2025/04/27 23:04:22 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

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

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (!ft_display_file(argv[1]))
			write(1, "Cannot read file.", 17);
	}
	else
	{
		if (argc < 2)
			write(1, "File name missing.", 18);
		else
			write(1, "Too many arguments.", 19);
	}
	return (0);
}
