/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:42:56 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/28 10:17:58 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_u_fd(unsigned int n, int fd, int *num)
{
	char	digit;

	if (n / 10 > 0)
		ft_putnbr_fd_f(n / 10, fd, num);
	digit = '0' + (n % 10);
	ft_putchar_fd(digit, fd);
	*num = *num + 1;
}
