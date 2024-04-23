/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ui_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:38:47 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/04 18:47:02 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstr_ui_fd(unsigned int i, int fd, int *num, int is_ul_case)
{
	char	digit;

	if (i / 16 > 0)
		ft_putstr_ui_fd(i / 16, fd, num, is_ul_case);
	if (i % 16 >= 10)
	{
		if (is_ul_case)
			digit = 'a' + (i % 16 - 10);
		else
			digit = 'A' + (i % 16 - 10);
	}
	else
		digit = '0' + i % 16;
	ft_putchar_fd(digit, fd);
	*num = *num + 1;
}
