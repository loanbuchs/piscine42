/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_src1                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:22:35 by loan              #+#    #+#             */
/*   Updated: 2025/05/14 15:39:20 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			result *= 10;
			result += *str - '0';
			str++;
		}
		else
			return (-1);
	}
	return (result);
}

int	ft_display(char *file_name, int bytes)
{
	int		file;
	int		reading;
	char	buffer;
	int		i;

	i = 0;
	file = open(file_name, 0);
	while (i < bytes)
	{
		reading = read(file, &buffer,1);
		i++;
	}
	while ((reading = read(file, &buffer, 1)))
		write(1, &buffer, 1);
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