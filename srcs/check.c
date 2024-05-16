/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:35:18 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/16 23:23:57 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

static long	extract_integer(char *s, long sign)
{
	long	num;

	num = 0;
	while ('0' <= *s && *s <= '9')
	{
		if (sign == 1 && ((num == INT_MAX / 10 && (*s - '0') > INT_MAX % 10)
				|| num > INT_MAX / 10))
		{
			num = LONG_MAX;
			break ;
		}
		if (sign == -1 && ((num == INT_MIN / 10 * (-1) && (*s - '0') > INT_MIN
					% 10 * (-1)) || num > INT_MIN / 10 * (-1)))
		{
			num = LONG_MIN;
			break ;
		}
		num = (*s++ - '0') + num * 10;
	}
	return (sign * num);
}

int	check_args_num(int argc)
{
	if (argc < 5 || argc > 6)
	{
		write(STDERR_FILENO, "Usage:", 6);
		write(STDERR_FILENO, " philo", 6);
		write(STDERR_FILENO, " [number_of_philosopher]", 24);
		write(STDERR_FILENO, " [time_to_die]", 14);
		write(STDERR_FILENO, " [time_to_eat]", 14);
		write(STDERR_FILENO, " [time_to_sleep]", 16);
		write(STDERR_FILENO, " [number_of_times_", 18);
		write(STDERR_FILENO, "each_philosopher_must_eat]\n", 28);
		return (1);
	}
	return (0);
}

int	check_front_zero_next(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '0' && argv[i][1] != '\0' && (argv[i][1] >= '0'
				|| argv[i][1] <= '9'))
		{
			write(STDERR_FILENO,
				"Error: Argument must be a number greater than 0\n", 48);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_int(int argc, char *argv[])
{
	int	i;
	int	j;

	if (extract_integer(argv[1], 1) > INT_MAX)
	{
		write(STDERR_FILENO,
			"Error: Argument must be a number less than INT_MAX\n", 52);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j++] > '9')
			{
				write(STDERR_FILENO, "Error: Argument must be a number\n", 33);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
