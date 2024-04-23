/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:00 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/04 18:24:22 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_u(int *num, va_list args)
{
	unsigned int	i;

	i = (unsigned int)va_arg(args, unsigned int);
	ft_putnbr_u_fd(i, 1, num);
}
