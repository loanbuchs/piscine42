/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 00:32:52 by loan              #+#    #+#             */
/*   Updated: 2025/05/28 01:06:47 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	comparestr(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	char	*save;

	i = 1;
	while (tab[i + 1])
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
	while (tab[i + 1])
	{
		if (comparestr(tab[i], tab[i + 1]) > 0)
			ft_sort_string_tab(tab);
		i++;
	}
}
