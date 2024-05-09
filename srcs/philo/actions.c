/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:31:07 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/07 17:54:12 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_simulation_params *param)
{
	usleep(10 * 1000);
	(void)param;
}

void	eat(t_simulation_params *param)
{
	usleep(param->eat_time * 1000);
	(void)param;
}

void	sleep(t_simulation_params *param)
{
	usleep(param->sleep_time * 1000);
	(void)param;
}
