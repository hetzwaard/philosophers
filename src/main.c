/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 01:19:30 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/11/16 19:40:06 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (ac != 5 && ac != 6)
		return (ft_error(ERR_ARG_COUNT), ERROR);
	if (check_args(av))
		return (ERROR);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(av[1]));
	init_philos(philos, &program, forks, av);
	init_threads(&program, forks);
	ft_destroy(NULL, &program, forks);
	return (SUCCESS);
}
