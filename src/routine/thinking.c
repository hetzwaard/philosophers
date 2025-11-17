/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thinking.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/10 14:31:55 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/07/22 13:02:32 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	thinking(t_philo *philo)
{
	size_t	delay;

	ft_print_msg(THINKING, philo, philo->id);
	delay = 0;
	if (philo->number_of_philosophers % 2 != 0 && philo->id % 2 == 0)
	{
		if (philo->time_to_die > philo->time_to_eat + philo->time_to_sleep)
		{
			delay = philo->time_to_die
				- (philo->time_to_eat + philo->time_to_sleep);
			if (delay > philo->time_to_eat)
				delay = philo->time_to_eat;
		}
	}
	if (delay > 0)
		ft_usleep(delay, philo);
}
