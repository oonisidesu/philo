/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:26 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/01 17:47:25 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	//char	str[14];
	int		length;

	//str[14] = "";
	printf("--orignal--\n");
	//length = strlen((void *)0);
	printf("文字列の長さは %d です。\n", length);
	printf("--ft--\n");
	length = ft_strlen((void *)0);
	printf("文字列の長さは %d です。\n", length);
	return (0);
}
 */