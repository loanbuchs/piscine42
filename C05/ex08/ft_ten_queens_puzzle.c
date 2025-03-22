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

int	iscorrect(int *position)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (i != j)
			{
				if (position[i] == position[j])
					return (0);
				if (position[i] == position[j] + j - i)
					return (0);
				if (position[i] == position[j] - j + i)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	isfinished(int *configuration)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (configuration[i] != 9)
			return (0);
		i++;
	}
	return (1);
}

void	printsolution(int *solution)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = solution[i] + '0';
		write(1, &c, 1);
		i++;
	}
	c = '\n';
	write(1, &c, 1);
}

int	*findsolutions(int *configuration, int count)
{
	int	i;

	i = 0;
	configuration[i]++;
	while (i < 10)
	{
		if (configuration[i] == 10 && i < 9)
		{
			configuration[i + 1]++;
			configuration[i] = 0;
		}
		i++;
	}
	if (count < 100000)
	{
		if (!iscorrect(configuration) && !isfinished(configuration))
			configuration = findsolutions(configuration, count + 1);
	}
	return (configuration);
}

int	ft_ten_queens_puzzle(void)
{
	int	initialconfiguration[10];
	int	*lastconfiguration;
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (i < 10)
	{
		initialconfiguration[i] = 0;
		i++;
	}
	lastconfiguration = initialconfiguration;
	while (!isfinished(lastconfiguration))
	{
		lastconfiguration = findsolutions(lastconfiguration, 0);
		if (!isfinished(lastconfiguration) && iscorrect(lastconfiguration))
		{
			printsolution(lastconfiguration);
			result++;
		}
	}
	return (result);
}
