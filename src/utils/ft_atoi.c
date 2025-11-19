/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 02:56:45 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/07/11 02:20:50 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	ft_atoi(char *str)
{
	long	sign;
	long	num;
	long	i;

	i = 0;
	sign = 1;
	num = 0;
	while ((ft_isspace(str[i])))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - 48);
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			return (FAILURE);
		i++;
	}
	return (num * sign);
}
