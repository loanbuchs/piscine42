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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*initialaddr;

	initialaddr = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src ++;
	}
	*dest = 0;
	return (initialaddr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		strsize;
	int		i;

	i = 0;
	strsize = 0;
	if (size == 0)
		return (NULL);
	while (i++ < size)
	{
		strsize += ft_strlen(strs[i - 1]);
		if (i < size)
			strsize += ft_strlen(sep);
	}
	strsize++;
	str = (char *) malloc(strsize);
	str[0] = 0;
	i = 0;
	while (i++ < size)
	{
		ft_strcat(str, strs[i - 1]);
		if (i < size)
			ft_strcat(str, sep);
	}
	return (str);
}
