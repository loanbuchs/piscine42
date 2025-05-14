/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_head.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:25:04 by loan              #+#    #+#             */
/*   Updated: 2025/05/14 15:35:02 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
#define FT_TAIL_H

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>



int	ft_atoi(char *str);
int	ft_strlen(char *str);
int	ft_display(char *file_name, int bytes);

#endif 
