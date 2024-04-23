/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:23:38 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 18:28:54 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/* int	main(void)
{
	const char	*str;
	char		searchchar;
	const char	*result;
	const char	*result_ft;

	str = "Hello, World!";
	searchchar = 'l';
	printf("--orignal--\n");
	//result = strchr(str, 'l' + 256);
	result = strchr(str, INT_MIN);
	//result = strchr(NULL, 'l' + 256);
	if (result != NULL)
		printf("%c: %ld\n", searchchar, result - str);
	else
		printf("文字 '%c' は文字列内で見つかりませんでした。\n", searchchar);
	printf("--ft--\n");
	//result_ft = ft_strchr(str, 'l' + 256);
	result_ft = ft_strchr(str, INT_MIN);
	// result_ft = ft_strchr(NULL, 'l' + 256);
	if (result_ft != NULL)
		printf("%c: %ld\n", searchchar, result_ft - str);
	else
		printf("文字 '%c' は文字列内で見つかりませんでした。\n", searchchar);
	return (0);
}
 */