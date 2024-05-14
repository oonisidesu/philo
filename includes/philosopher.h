/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:08:39 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/10 13:39:11 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// philosopher.h

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "philo.h"

typedef enum e_philo_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}					t_philo_state;

typedef struct s_philosopher
{
	int				id;
	t_philo_state	state;
	int				times_eaten;
	struct timeval	last_meal_time;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
	t_philo_data	*shared_data;
}					t_philosopher;

// 哲学者の行動を制御する関数プロトタイプ
void				take_forks(t_philosopher *philo);
void				eat(t_philosopher *philo);
void				drop_forks(t_philosopher *philo);
void				sleep_and_think(t_philosopher *philo);
void				check_death(t_philosopher *philo,
						struct timeval current_time);

#endif // PHILOSOPHER_H
