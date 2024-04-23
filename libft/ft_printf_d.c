/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:14 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/28 10:17:48 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_d(int *num, va_list args)
{
	int	i;

	i = (int)va_arg(args, int);
	ft_putnbr_fd_f(i, 1, num);
}
