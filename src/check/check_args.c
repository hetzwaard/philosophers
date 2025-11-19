/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/11 01:59:12 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/11/16 19:37:08 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	check_arg(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	check_args(char **av)
{
	if (ft_atoi(av[1]) > PHILO_MAX || ft_atoi(av[1]) <= 0 || check_arg(av[1]))
		return (ft_error(ERR_PHI_NMBR), ERROR);
	if (ft_atoi(av[2]) <= 0 || check_arg(av[2]))
		return (ft_error(ERR_DIE_TIME), ERROR);
	if (ft_atoi(av[3]) <= 0 || check_arg(av[3]))
		return (ft_error(ERR_EAT_TIME), ERROR);
	if (ft_atoi(av[4]) <= 0 || check_arg(av[4]))
		return (ft_error(ERR_SLP_TIME), ERROR);
	if (av[5] && (ft_atoi(av[5]) < 0 || check_arg(av[5])))
		return (ft_error(ERR_EAT_NMBR), ERROR);
	return (SUCCESS);
}
