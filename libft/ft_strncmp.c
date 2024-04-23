/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:03:25 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/02 16:32:36 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (unsigned char)s1[i] == (unsigned char)s2[i])
	{
		if (s1[i] == '\0')
			break ;
		i++;
	}
	if (i == n)
		return (0);
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

/* #include <limits.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[30] = "libft-test-tokyo";
	char	str2[10] = "libft";
	int		result_ori;
	int		result_ft;

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