/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:11:47 by yootsubo          #+#    #+#             */
/*   Updated: 2024/04/23 13:30:42 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// __attribute__((destructor)) static void destructor(void)
// {
// 	system("leaks -q fractol");
// }

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (check_args(argc, argv))
	{
		print_display_available_parameters();
		return (0);
	}
	init_window(&f, argc, argv);
	render(&f);
	event_hook(&f);
	mlx_loop(f.vars.mlx);
	return (0);
}
