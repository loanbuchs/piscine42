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
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	baseincorrect(char *base, int lenbase)
{
	int	i;
	int	j;

	i = 0;
	if (lenbase < 2)
		return (1);
	while (*(base + i))
	{
		if (*(base + i) == '+' || *(base + i) == '-' || ft_isspace(*(base + i)))
			return (1);
		j = 0;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j) && i != j)
				return (1);
			j ++;
		}
		i++;
	}
	return (0);
}

int	nbinbase(char c, char *base)
{
	int	i;

	i = 0;
	while (*(base + i))
	{
		if (c == *(base + i))
			return (i + 1);
		i++;
	}
	return (0);
}
