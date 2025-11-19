/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_program.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/10 14:35:55 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/11/16 22:50:10 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	init_program(t_program *program, t_philo *philos)
{
	program->number_of_forks = 0;
	program->dead_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}
