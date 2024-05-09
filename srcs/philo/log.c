/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:15:55 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/07 16:51:45 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_state_change(pthread_mutex_t *mutex, int philosopher_id,
		char *state, int timestamp)
{
	pthread_mutex_lock(mutex);
	printf("%dms: Philosopher %d is %s.\n", timestamp, philosopher_id, state);
	pthread_mutex_unlock(mutex);
}
