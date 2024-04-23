/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:34:11 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/05 08:18:06 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_s(int *num, va_list args)
{
	char	*s;
	char	*c;

	c = "(null)";
	s = (char *)va_arg(args, char *);
	if (s != NULL)
	{
		*num = *num + ft_strlen(s);
		ft_putstr_fd(s, 1);
	}
	else
	{
		*num = *num + ft_strlen(c);
		ft_putstr_fd(c, 1);
	}
}
