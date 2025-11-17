/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/10 14:37:31 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/07/10 14:37:38 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	init_input(t_philo *philo, char **argv)
{
	philo->number_of_philosophers = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->number_of_meals = ft_atoi(argv[5]);
	else
		philo->number_of_meals = -1;
}
