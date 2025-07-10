/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/08 01:19:58 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/07/11 02:31:30 by mahkilic      ########   odam.nl         */
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

# define TRUE 1
# define FALSE 0

# define SUCCESS 0
# define ERROR 1

# define DIED "died"
# define TAKEN_FORK "has taken a fork"
# define EATING "is eating"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"

# define WRONG_ARGS "input must be an integer larger than 0"

# define PHILO_MAX 300

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;
typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

/* check */
int		check_args(char **argv);
void	*monitor(void *pointer);

/* init */
void	init_forks(pthread_mutex_t *forks, int philo_num);
void	init_input(t_philo *philo, char **argv);
void	init_philos(t_philo *philos, t_program *program,
			pthread_mutex_t *forks, char **argv);
void	init_program(t_program *program, t_philo *philos);
int		init_threads(t_program *program, pthread_mutex_t *forks);

/* routine */
int		ft_dead_loop(t_philo *philo);
void	*ft_routine(void *pointer);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

/* utils */
int		ft_atoi(char *str);
void	ft_destroy(char *str, t_program *program, pthread_mutex_t *forks);
size_t	ft_gettimeofday(void);
void	ft_print_msg(char *str, t_philo *philo, int id);
int		ft_strlen(char *str);
int		ft_usleep(size_t milliseconds);

#endif