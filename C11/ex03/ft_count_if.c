/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:26:58 by loan              #+#    #+#             */
/*   Updated: 2025/05/26 13:35:12 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	save;

	save = length;
	count = 0;
	while (length)
	{
		if (f(tab[save - length]))
			count++;
		length--;
	}
	return (count);
}
