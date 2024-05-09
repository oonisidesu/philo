/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:20:05 by yootsubo          #+#    #+#             */
/*   Updated: 2024/05/07 15:39:49 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static char	*skip_whitespace_signs(const char *str)
{
	while (*str == '\0' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	return ((char *)str);
}

static int	extract_sign(const char *str)
{
	int	sign;

	sign = 1;
	while (*str == '\0' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
		sign *= -1;
	return (sign);
}

static long	extract_integer(char *s, int sign)
{
	long	num;

	num = 0;
	while ('0' <= *s && *s <= '9')
	{
		if (sign == 1 && ((num == LONG_MAX / 10 && (*s - '0') > LONG_MAX % 10)
				|| num > LONG_MAX / 10))
		{
			num = LONG_MAX;
			break ;
		}
		if (sign == -1 && ((num == LONG_MIN / 10 * (-1) && (*s - '0') > LONG_MIN
					% 10 * (-1)) || num > LONG_MIN / 10 * (-1)))
		{
			num = LONG_MIN;
			break ;
		}
		num = (*s++ - '0') + num * 10;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	num;
	char	*s;

	s = skip_whitespace_signs(str);
	sign = extract_sign(str);
	num = extract_integer(s, sign);
	return (sign * (int)num);
}
