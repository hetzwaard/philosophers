/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_usleep.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/10 14:30:12 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/11/16 19:38:02 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = ft_gettimeofday();
	while ((ft_gettimeofday() - start) < milliseconds)
		usleep(500);
	return (SUCCESS);
}
