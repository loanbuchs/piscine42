/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exempleheader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:50:20 by marvin            #+#    #+#             */
/*   Updated: 2025/02/10 11:50:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_BOOLEAN_H
# include <unistd.h>

typedef int	t_bool;

# define FT_BOOLEAN_H
# define TRUE 1
# define FALSE 0
# define EVEN(nbr) (nbr % 2 == 0)
# define EVEN_MSG "I have an even number of arguments."
# define ODD_MSG "I have an odd number of arguments."
# define SUCCESS 0

#endif
