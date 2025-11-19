/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 01:19:58 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/11/16 19:35:31 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

# define PHILO_MAX 200

# define TRUE 1
# define FALSE 0

# define SUCCESS 0
# define ERROR 1
# define FAILURE -1

# define DIED "died"
# define TAKEN_FORK "has taken a fork"
# define EATING "is eating"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"

# define ERR_ARG_COUNT "Wrong argument count"
# define ERR_EAT_NMBR "Invalid number of times each philosopher must eat"
# define ERR_PHI_NMBR "Invalid number of philosophers"
# define ERR_DIE_TIME "Invalid time to die"
# define ERR_EAT_TIME "Invalid time to eat"
# define ERR_SLP_TIME "Invalid time to sleep"
# define ERR_OVERFLOW "Invalid input"

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				finished;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				number_of_philosophers;
	int				number_of_meals;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				number_of_forks;
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

/* check */
int		check_args(char **av);
void	*monitor(void *pointer);

/* init */
int		init_forks(t_program *program, pthread_mutex_t *forks,
			int number_of_philosophers);
void	init_input(t_philo *philo, char **argv);
void	init_philos(t_philo *philos, t_program *program,
			pthread_mutex_t *forks, char **argv);
void	init_program(t_program *program, t_philo *philos);
int		init_threads(t_program *program, pthread_mutex_t *forks);

/* routine */
int		dead_loop(t_philo *philo);
void	*routine(void *pointer);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

/* utils */
int		ft_atoi(char *str);
void	ft_destroy(char *str, t_program *program, pthread_mutex_t *forks);
void	ft_error(char *str);
size_t	ft_gettimeofday(void);
void	ft_print_msg(char *str, t_philo *philo, int id);
int		ft_strlen(char *str);
int		ft_usleep(size_t milliseconds, t_philo *philo);

#endif
