/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:03:55 by loan              #+#    #+#             */
/*   Updated: 2025/05/28 00:27:50 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ops.h>

int	getvalue(char *str)
{
	int	i;
	int	value;
	int	neg;

	i = 0;
	value = 0;
	neg = 0;
	if (str[0] == '-')
	{
		neg = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	if (neg)
		return (-value);
	return (value);
}

int	main(int argc, char *argv[])
{
	int		value1;
	int		value2;
	void	(*operations[5])(int, int);

	operations[0] = add;
	operations[1] = sub;
	operations[2] = mult;
	operations[3] = div;
	operations[4] = modulo;
	value1 = getvalue(argv[1]);
	value2 = getvalue(argv[3]);
	if (argv[2][0] == '+')
		operations[0](value1, value2);
	if (argv[2][0] == '-')
		operations[1](value1, value2);
	if (argv[2][0] == '*')
		operations[2](value1, value2);
	if (argv[2][0] == '/')
		operations[3](value1, value2);
	if (argv[2][0] == '%')
		operations[4](value1, value2);
	return (argc);
}
