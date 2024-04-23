/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:43:35 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 17:56:43 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == INT_MIN)
	{
		if (write(fd, "-2147483648", 11) == -1)
			return ;
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		if (write(fd, "-", 1) == -1)
			return ;
	}
	if (n / 10 > 0)
		ft_putnbr_fd(n / 10, fd);
	digit = '0' + (n % 10);
	ft_putchar_fd(digit, fd);
}

/* int	main(void)
{
	ft_putnbr_fd(1234, 0);
    write(0, "\n", 1);
	ft_putnbr_fd(-1234, 0);
    write(0, "\n", 1);
	ft_putnbr_fd(0, 0);
    write(0, "\n", 1);
	ft_putnbr_fd(INT_MAX, 0);
    write(0, "\n", 1);
	ft_putnbr_fd(INT_MIN, 0);
}
 */