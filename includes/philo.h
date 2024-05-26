/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:13 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/26 16:34:44 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				num_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				num_must_eat;
	int				all_ate;
	int				dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	dead_mutex;
	long long		start_time;
}					t_data;

typedef struct s_philo
{
	int				id;
	long long		last_meal;
	int				meals_eaten;
	pthread_t		thread;
	t_data			*data;
}					t_philo;

int					print_error(char *msg);
long long			ft_atoll(const char *str);
long long			get_time(void);
void				print_action(t_philo *philo, char *action);
void				free_all(t_philo *philos);
void				sleep_for(long long duration);

int					init_data(t_data *data, int argc, char **argv);
int					set_data_values(t_data *data, int argc, char **argv);
int					initialize_mutexes(t_data *data);
t_philo				*init_philos(t_data *data);
int					start_simulation(t_philo *philos);
int					create_threads(t_philo *philos);
void				join_threads(t_philo *philos);
void				*philo_routine(void *arg);
void				run_philo_routine(t_philo *philo);
void				take_forks(t_philo *philo, int left_fork, int right_fork);
void				put_down_forks(t_philo *philo, int left_fork,
						int right_fork);
void				perform_eating(t_philo *philo, t_data *data);
void				perform_sleeping(t_philo *philo, t_data *data);
void				check_death(t_philo *philos);
int					check_each_philo(t_philo *philos);
void				check_all_ate(t_philo *philos);

#endif
