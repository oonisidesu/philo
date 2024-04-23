/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:46:15 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:17:40 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	while (*s != '\0')
	{
		s++;
		counter++;
	}
	if (*s == (char)c)
		return ((char *)s);
	while (counter != -1)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		counter--;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*str;
	char		searchchar;
	char		*result;

	str = "Hello, World!";
	searchchar = '\0';
	printf("--orignal--\n");
	result = strrchr(str, -325678);
	if (result != NULL)
		printf("文字 '%c' は文字列内で最後に見つかった位置は: %ld\n", searchchar, result - str);
	else
		printf("文字 '%c' は文字列内で見つかりませんでした。\n", searchchar);
	printf("--ft--\n");
	result = ft_strrchr(str, -325678);
	if (result != NULL)
		printf("文字 '%c' は文字列内で最後に見つかった位置は: %ld\n", searchchar, result - str);
	else
		printf("文字 '%c' は文字列内で見つかりませんでした。\n", searchchar);
	return (0);
}
 */