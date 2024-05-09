/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:51:47 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/07 17:56:49 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# define MAX_PHILOSOPHERS 10

typedef struct s_simulation_params
{
	int	num_philosophers;
	int	death_time;
	int	eat_time;
	int	sleep_time;
	int	max_meals;
}		t_simulation_params;

void	*philosopher(void *arg);
void	simulate_philosophers(t_simulation_params *params);
void	log_state_change(pthread_mutex_t *mutex, int philosopher_id,
			char *state, int timestamp);
void	acquire_forks(int philosopher_id, pthread_mutex_t *fork_mutexes,
			t_simulation_params *params);
void	release_forks(int philosopher_id, pthread_mutex_t *fork_mutexes,
			t_simulation_params *params);
void	simulate_think(t_simulation_params *param);
void	simulate_eat(t_simulation_params *param);
void	simulate_sleep(t_simulation_params *param);

#endif
