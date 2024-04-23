/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:55:06 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/04 18:37:43 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_p(int *num, va_list args)
{
	unsigned long long	l;

	l = (unsigned long long)va_arg(args, unsigned long long);
	ft_putstr_fd("0x", 1);
	*num = *num + 2;
	ft_putstr_long_fd(l, 1, num);
}
