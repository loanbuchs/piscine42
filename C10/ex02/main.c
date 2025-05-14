/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:00:48 by loan              #+#    #+#             */
/*   Updated: 2025/05/14 15:53:40 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <ft_tail.h>

int	ft_size_file(char *file_name)
{
	int		file;
	char	buffer;
	int		size;

	size = 0;
	file = open(file_name, 0);
	if (file < 0)
	{
		write(2, "ft_tail: ", 9);
		while (*file_name)
			write(2, file_name++, 1);
		write(2, ": No such file or directory\n", 28);
		return (-1);
	}
	while (read(file, &buffer, 1) > 0)
		++size;
	close(file);
	return (size);
}

int	canrun(char *argv1, char *argv2, int argc)
{
	int	bytes;

	if (!(*argv1 == '-' && argv1[1] == 'c' && argv1[2] == 0))
	{
		write(1, "use option -c", 13);
		return (0);
	}
	if (argc < 3)
	{
		write(1, "tail: option requires an argument -- 'c'", 40);
		return (0);
	}
	bytes = ft_atoi(argv2);
	if (bytes < 0)
	{
		write(1, "tail: invalid number of bytes: '", 32);
		write(1, argv2, ft_strlen(argv2));
		write(1, "'", 1);
		return (0);
	}
	return (1);
}

int	ft_tail_stdin(int bytes)
{
	char	buffer[30000];
	int		i;

	i = 0;
	while (read(0, &buffer[i], 1))
		i++;
	buffer[i] = 0;
	if (i >= bytes)
	{
		while (buffer[i - bytes])
		{
			write(1, &buffer[i - bytes], 1);
			bytes--;
		}
	}
	else
	{
		i = 0;
		while (buffer[i])
		{
			write(1, &buffer[i], 1);
			i++;
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	fsize;
	int	i;
	int	bytes;

	i = canrun(argv[1], argv[2], argc);
	if (i)
	{
		bytes = ft_atoi(argv[2]);
		i = 3;
		while (i < argc)
		{
			fsize = ft_size_file(argv[i]);
			if (fsize > 0)
				ft_display(argv[i], fsize - bytes);
			i++;
		}
		if (argc == 3)
			ft_tail_stdin(bytes);
	}
	return (0);
}
