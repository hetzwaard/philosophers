/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 02:14:06 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/11/16 19:39:26 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	meal_loop(t_philo *philo)
{
	if (philo->number_of_meals == -1)
		return (FALSE);
	pthread_mutex_lock(philo->meal_lock);
	if (philo->meals_eaten >= philo->number_of_meals)
	{
		philo->finished = TRUE;
		return (pthread_mutex_unlock(philo->meal_lock), TRUE);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (FALSE);
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (SUCCESS);
}

void	*routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->number_of_philosophers % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_usleep(50, philo);
	}
	else if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_eat, philo);
	while (!dead_loop(philo))
	{
		eating(philo);
		if (meal_loop(philo))
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (pointer);
}
