/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eating.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/10 14:34:07 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/11/14 20:04:57 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	case_one_philo(t_philo *philo, pthread_mutex_t **first)
{
	if (philo->number_of_philosophers == 1)
	{
		ft_usleep(philo->time_to_die, philo);
		pthread_mutex_unlock(*first);
		return (ERROR);
	}
	return (SUCCESS);
}

static void	case_deadlock(t_philo *philo, pthread_mutex_t **first,
	pthread_mutex_t **second)
{
	if (philo->id % 2 == 0)
	{
		*first = philo->l_fork;
		*second = philo->r_fork;
	}
	else
	{
		*first = philo->r_fork;
		*second = philo->l_fork;
	}
}

void	eating(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	case_deadlock(philo, &first, &second);
	pthread_mutex_lock(first);
	ft_print_msg(TAKEN_FORK, philo, philo->id);
	if (case_one_philo(philo, &first))
		return ;
	pthread_mutex_lock(second);
	ft_print_msg(TAKEN_FORK, philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = ft_gettimeofday();
	philo->eating = 1;
	pthread_mutex_unlock(philo->meal_lock);
	ft_print_msg(EATING, philo, philo->id);
	ft_usleep(philo->time_to_eat, philo);
	pthread_mutex_lock(philo->meal_lock);
	philo->meals_eaten++;
	philo->eating = 0;
	pthread_mutex_unlock(philo->meal_lock);
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
}
