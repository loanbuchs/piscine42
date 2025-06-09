/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 00:49:37 by loan              #+#    #+#             */
/*   Updated: 2025/05/28 01:05:50 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*save;

	i = 1;
	while (tab[i + 1])
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
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
		if (cmp(tab[i], tab[i + 1]) > 0)
			ft_advanced_sort_string_tab(tab, cmp);
		i++;
	}
}
