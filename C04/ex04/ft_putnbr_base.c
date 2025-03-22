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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
		if (*(base + i) == '+' || *(base + i) == '-')
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	lenbase;

	lenbase = ft_strlen(base);
	if (baseincorrect(base, lenbase))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > (lenbase - 1))
	{
		ft_putnbr_base(nbr / lenbase, base);
		ft_putnbr_base(nbr % lenbase, base);
	}
	else
		write(1, &base[nbr], 1);
}
