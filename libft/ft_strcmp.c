/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:03:25 by yootsubo          #+#    #+#             */
/*   Updated: 2023/12/11 12:18:04 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i])
	{
		if (s1[i] == '\0')
			break ;
		i++;
	}
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

/* #include <limits.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[30];
	char	str2[10];
	int		result_ori;
	int		result_ft;

	str1[30] = "libft-test-tokyo";
	str2[10] = "libft";
	str2[5] = CHAR_MIN;
	printf("--orignal--\n");
	result_ori = strncmp(str1, str2, sizeof(str1));
	if (result_ori < 0)
		printf("str1はstr2よりも小さい\n");
	else if (result_ori == 0)
		printf("str1とstr2は等しい\n");
	else
		printf("str1はstr2よりも大きい\n");
	printf("--ft--\n");
	result_ft = ft_strncmp(str1, str2, sizeof(str1));
	if (result_ft < 0)
		printf("str1はstr2よりも小さい\n");
	else if (result_ft == 0)
		printf("str1とstr2は等しい\n");
	else
		printf("str1はstr2よりも大きい\n");
	return (0);
}
 */