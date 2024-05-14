/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:17:20 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/10 12:47:38 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// utils.c

#include "utils.h"
#include <stdio.h>
#include <sys/time.h>

// 現在の時間を取得する関数
void	get_current_time(struct timeval *tv)
{
	gettimeofday(tv, NULL);
}

// 2つの時間の差をミリ秒で計算する関数
long	get_time_diff(struct timeval *start, struct timeval *end)
{
	long	seconds;
	long	microseconds;

	seconds = end->tv_sec - start->tv_sec;
	microseconds = end->tv_usec - start->tv_usec;
	return (seconds * 1000 + microseconds / 1000);
}

// 哲学者のアクションをログに記録する関数
void	log_philosopher_action(t_philosopher *philo, const char *action)
{
	struct timeval	current_time;
	long			timestamp;

	get_current_time(&current_time);
	timestamp = get_time_diff(&(philo->shared_data->simulation_start),
			&current_time);
	pthread_mutex_lock(&(philo->shared_data->write_mutex));
	printf("%ld %d %s\n", timestamp, philo->id, action);
	pthread_mutex_unlock(&(philo->shared_data->write_mutex));
}
