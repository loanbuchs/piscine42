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

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

int	comparestr(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}

char	**ft_sort_tab(char **tab, int len)
{
	int		i;
	char	*save;

	i = 1;
	while (i < len)
	{
		if (comparestr(tab[i], tab[i + 1]) > 0)
		{
			save = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = save;
		}
		i++;
	}
	i = 1;
	while (i < len)
	{
		if (comparestr(tab[i], tab[i + 1]) > 0)
			tab = ft_sort_tab(tab, len);
		i++;
	}
	return (tab);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	**sorted;

	sorted = ft_sort_tab(argv, argc - 1);
	i = 1;
	while (argv[i])
	{
		ft_putstr(sorted[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
