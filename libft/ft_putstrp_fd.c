/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrp_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:21:31 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/03 18:07:38 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstrp_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	if (write(fd, s, ft_strlen(s)) == -1)
		return ;
}
