/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:28:13 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/18 17:28:14 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal_time;
	int				meals_eaten;
	struct s_table	*table;
}					t_philosopher;

typedef struct s_table
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nm_of_t_each_philo_must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	int				simulation_ended;
	t_philosopher	*philosophers;
}					t_table;

long				get_current_time_ms(void);
void				think(t_philosopher *philosopher);
void				eat(t_philosopher *philosopher, t_table *table);
void				sleep_philosopher(t_philosopher *philosopher,
						t_table *table);
void				*philosopher_thread(void *arg);
void				monitor_philosophers(t_table *table);
void				print_status(t_philosopher *philosopher, char *status);
int					ft_atoi(const char *str);
int					check_args_num(int argc);
int					check_front_zero_next(int argc, char *argv[]);
int					check_int(int argc, char *argv[]);

#endif
