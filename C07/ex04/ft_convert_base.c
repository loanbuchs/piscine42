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

int	ft_strlen(char *str);
int	ft_isspace(char c);
int	baseincorrect(char *base, int lenbase);
int	nbinbase(char c, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int	lenbase;
	int	result;
	int	negorpos;

	negorpos = 1;
	result = 0;
	while (ft_isspace(*(str)))
		str++;
	lenbase = ft_strlen(base);
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negorpos = -negorpos;
		str++;
	}
	while (nbinbase(*str, base))
	{
		result *= lenbase;
		result += nbinbase(*str, base) - 1;
		str++;
	}
	result *= negorpos;
	return (result);
}

char	*ft_putnbr_base(int nbr, char *base, int lenresult)
{
	int		lenbase;
	char	*result;

	result = (char *) malloc(lenresult);
	lenbase = ft_strlen(base);
	if (nbr < 0)
	{
		*result = '-';
		nbr = -nbr;
	}
	*(result + lenresult - 1) = '\0';
	lenresult--;
	while (nbr)
	{
		*(result + lenresult - 1) = base[nbr % lenbase];
		nbr /= lenbase;
		lenresult--;
	}
	return (result);
}

int	lenresult(int nbr, char *base_to)
{
	int	len;
	int	lenbase;

	lenbase = ft_strlen(base_to);
	len = 1;
	if (nbr < 0)
		len++;
	while (nbr)
	{
		nbr /= lenbase;
		len++;
	}
	return (len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbrten;
	char	*result;
	int		len_basefrom;
	int		len_baseto;

	len_baseto = ft_strlen(base_to);
	len_basefrom = ft_strlen(base_from);
	if (baseincorrect(base_from, len_basefrom)
		|| baseincorrect(base_to, len_baseto))
		return (NULL);
	nbrten = ft_atoi_base(nbr, base_from);
	result = ft_putnbr_base(nbrten, base_to, lenresult(nbrten, base_to));
	return (result);
}
