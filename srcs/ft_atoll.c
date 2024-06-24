/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:36:13 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/06/24 15:20:25 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoll(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			break ;
		res = res * 10 + (*str - '0');
		if (res < INT_MIN || res > INT_MAX)
			return (INT_MAX + (long)1);
		str++;
	}
	return (res * sign);
}
