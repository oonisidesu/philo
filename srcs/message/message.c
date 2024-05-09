/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:00:03 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/07 14:56:34 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message.h"
#include <stdio.h>

void	print_arg_err(void)
{
	printf("usage : ");
	printf("<num_philosophers> ");
	printf("<death_time> ");
	printf("<eat_time> ");
	printf("<sleep_time> ");
	printf("[<max_meals>]\n");
}
