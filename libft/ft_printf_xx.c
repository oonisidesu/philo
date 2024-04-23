/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:08 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/04 18:56:18 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_xx(int *num, va_list args)
{
	unsigned int	i;

	i = (unsigned int)va_arg(args, unsigned int);
	ft_putstr_ui_fd(i, 1, num, 0);
}
