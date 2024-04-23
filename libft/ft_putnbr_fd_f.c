/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:42:56 by yootsubo          #+#    #+#             */
/*   Updated: 2023/11/02 12:33:13 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_fd_f(int n, int fd, int *num)
{
	char	digit;
	char	*int_min_str;

	int_min_str = "-2147483648";
	if (n == INT_MIN)
	{
		if (write(fd, int_min_str, 11) == -1)
			return ;
		*num = *num + ft_strlen(int_min_str);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		*num = *num + 1;
		if (write(fd, "-", 1) == -1)
			return ;
	}
	if (n / 10 > 0)
		ft_putnbr_fd_f(n / 10, fd, num);
	digit = '0' + (n % 10);
	ft_putchar_fd(digit, fd);
	*num = *num + 1;
}
