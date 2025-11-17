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

static int	check_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	check_args(char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_arg(argv[1]))
		return (ft_error(ERR_PHI_NMBR), ERROR);
	if (ft_atoi(argv[2]) <= 0 || check_arg(argv[2]))
		return (ft_error(ERR_DIE_TIME), ERROR);
	if (ft_atoi(argv[3]) <= 0 || check_arg(argv[3]))
		return (ft_error(ERR_EAT_TIME), ERROR);
	if (ft_atoi(argv[4]) <= 0 || check_arg(argv[4]))
		return (ft_error(ERR_SLP_TIME), ERROR);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_arg(argv[5])))
		return (ft_error(ERR_EAT_NMBR), ERROR);
	return (SUCCESS);
}
