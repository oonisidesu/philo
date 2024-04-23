/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:20 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/28 10:17:54 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_i(int *num, va_list args)
{
	int	i;

	i = (int)va_arg(args, int);
	ft_putnbr_fd_f(i, 1, num);
}
