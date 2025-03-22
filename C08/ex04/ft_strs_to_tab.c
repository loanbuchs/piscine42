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
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

struct	s_stock_str	str_to_struct(char *str)
{
	t_stock_str	result;
	char		*copy;

	if (!str)
		return ((t_stock_str){0, NULL, NULL});
	copy = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!copy)
		return ((t_stock_str){0, NULL, NULL});
	result.size = ft_strlen(str);
	result.str = str;
	result.copy = ft_strcpy(copy, str);
	return (result);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*result;

	result = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!result)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		result[i] = str_to_struct(av[i]);
		i++;
	}
	result[i].str = NULL;
	result[i].copy = NULL;
	result[i].size = 0;
	return (result);
}
