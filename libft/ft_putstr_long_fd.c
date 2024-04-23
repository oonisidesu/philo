/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_long_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:32:36 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/04 18:37:55 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_long_fd(unsigned long long l, int fd, int *num)
{
	char	digit;

	if (l / 16 > 0)
		ft_putstr_long_fd(l / 16, fd, num);
	if (l % 16 >= 10)
		digit = 'a' + (l % 16 - 10);
	else
		digit = '0' + l % 16;
	ft_putchar_fd(digit, fd);
	*num = *num + 1;
}
