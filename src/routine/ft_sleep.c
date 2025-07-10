/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sleep.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/10 14:32:27 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/07/11 02:03:20 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	ft_sleep(t_philo *philo)
{
	ft_print_msg("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}
