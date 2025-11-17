/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sleeping.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/10 14:32:27 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/07/22 13:02:28 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	sleeping(t_philo *philo)
{
	ft_print_msg(SLEEPING, philo, philo->id);
	ft_usleep(philo->time_to_sleep, philo);
	if (philo->number_of_philosophers % 2 != 0 && philo->id % 2 == 1
		&& philo->time_to_die > philo->time_to_eat + philo->time_to_sleep)
		ft_usleep(philo->time_to_eat, philo);
}
