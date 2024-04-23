/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:00:59 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/04 16:21:51 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_c(int *num, va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	*num = *num + 1;
	ft_putchar_fd(c, 1);
}
