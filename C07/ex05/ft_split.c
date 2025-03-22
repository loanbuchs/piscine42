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
#include <stdlib.h>

int	isseparator(char totest, char *separators)
{
	int	i;

	i = 0;
	while (separators[i])
	{
		if (totest == separators[i])
			return (1);
		i++;
	}
	return (0);
}

int	nbrstr(char *str, char *charset)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 1;
	while (str[i])
	{
		if (isseparator(*(str + i), charset))
			if (!isseparator(*(str + i + 1), charset) && *(str + i + 1))
				nbr++;
		i++;
	}
	return (nbr);
}

char	*getstr(char *src, int size)
{
	char	*str;
	int		i;

	str = (char *) malloc(size * sizeof(char) + 1);
	i = 0;
	while (i < size)
	{
		str[i] = *(src - size + i);
		i++;
	}
	str[size] = '\0';
	return (str);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		size;
	char	**result;

	size = nbrstr(str, charset);
	result = (char **) malloc(size * sizeof(char *));
	j = 0;
	while (*str && j < size)
	{
		i = 0;
		while (!isseparator(str[i], charset) && *(str + i))
			i++;
		str += i;
		if (i)
		{
			result[j] = getstr(str, i);
			j++;
		}
		str++;
	}
	return (result);
}
