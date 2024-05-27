/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:00 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/27 17:34:40 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, int argc, char **argv)
{
	if (check_data_values(argc, argv))
		return (1);
	if (set_data_values(data, argc, argv))
		return (1);
	if (initialize_mutexes(data))
		return (1);
	data->start_time = get_time();
	return (0);
}

t_philo	*init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!philos)
		return (NULL);
	while (i < data->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].last_meal = get_time();
		philos[i].meals_eaten = 0;
		philos[i].data = data;
		i++;
	}
	return (philos);
}

int	start_simulation(t_philo *philos)
{
	if (create_threads(philos))
		return (1);
	check_death(philos);
	join_threads(philos);
	return (0);
}
