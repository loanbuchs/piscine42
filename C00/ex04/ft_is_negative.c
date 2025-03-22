/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:01:14 by marvin            #+#    #+#             */
/*   Updated: 2024/10/26 11:01:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	int	reponse;

	if (n < 0)
		reponse = 78;
	else
		reponse = 80;
	write (1, &reponse, 1);
}

// void	ft_is_negative(int n)
// {
// 	if (n < 0)
// 		write (1, "N", 1);
// 	else
// 		write (1, "P", 1);
// }