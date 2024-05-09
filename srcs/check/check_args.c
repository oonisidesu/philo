/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:53:14 by yootsubo          #+#    #+#             */
/*   Updated: 2024/05/07 15:42:57 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message.h"

int	check_args(int argc, char **argv)
{
	(void)argv;
	if (argc < 5 || argc > 6)
	{
		print_arg_err();
		return (1);
	}
	return (0);
}
