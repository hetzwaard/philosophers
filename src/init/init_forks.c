/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_forks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/10 14:36:28 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/07/10 14:36:35 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	init_forks(t_program *program, pthread_mutex_t *forks,
	int number_of_philosophers)
{
	int	i;

	program->number_of_forks = 0;
	i = 0;
	while (i < number_of_philosophers)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (ERROR);
		program->number_of_forks++;
		i++;
	}
	return (SUCCESS);
}
