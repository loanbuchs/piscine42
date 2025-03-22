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
int	ft_isspace(char *c)
{
	if (*c == ' ' || *c == '\t' || *c == '\n'
		|| *c == '\v' || *c == '\f' || *c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	negorpos;
	int	result;

	negorpos = 1;
	result = 0;
	while (ft_isspace(str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negorpos = -negorpos;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	result *= negorpos;
	return (result);
}
