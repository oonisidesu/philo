/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:11:47 by yootsubo          #+#    #+#             */
/*   Updated: 2024/05/07 15:44:30 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "philo.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

// __attribute__((destructor)) static void destructor(void)
// {
// 	system("leaks -q fractol");
// }

int	main(int argc, char *argv[])
{
	t_simulation_params	params;

	if (check_args(argc, argv))
		return (EXIT_FAILURE);
	params.num_philosophers = ft_atoi(argv[1]);
	params.death_time = ft_atoi(argv[2]);
	params.eat_time = ft_atoi(argv[3]);
	params.sleep_time = ft_atoi(argv[4]);
	// params.max_meals = (argc == 6) ? atoi(argv[5]) : -1;
	if (params.num_philosophers > MAX_PHILOSOPHERS)
	{
		printf("The maximum number of philosophers is %d\n", MAX_PHILOSOPHERS);
		return (1);
	}
	simulate_philosophers(&params);
	return (0);
}
