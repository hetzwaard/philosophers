/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_gettimeofday.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/10 14:30:36 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/07/11 02:08:39 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

size_t	ft_gettimeofday(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
