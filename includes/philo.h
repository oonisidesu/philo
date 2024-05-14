/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:06:52 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/14 17:36:02 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

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
	t_philosopher	*philosophers;
}					t_table;

long				get_current_time_ms(void);
void				think(t_philosopher *philosopher);
void				eat(t_philosopher *philosopher, t_table *table);
void				sleep_philosopher(t_philosopher *philosopher,
						t_table *table);
void				*philosopher_thread(void *arg);

#endif
