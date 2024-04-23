/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 12:24:29 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/02 16:56:01 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack != '\0' && len >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

/* int	main(void)
{
	const char	*haystack_ori;
	char		*result_ori;
	const char	*haystack_ft;
	char		*result_ft;

	haystack_ori = "Hello, World!Wo";
	//const char	*needle_ori = "";
	result_ori = "Hello, World!Wo";
	haystack_ft = "Hello, World!Wo";
	//const char	*needle_ft = "";
	result_ori = strnstr("libft-test-tokyo", "libft", 5);
	//result_ori = strnstr(((void *)0), "fake", 0);
	//result_ori = strnstr(haystack_ori, needle_ori, 9);
	result_ft = ft_strnstr("libft-test-tokyo", "libft", 5);
	//result_ft = ft_strnstr(((void *)0), "fake", 0);
	//result_ft = ft_strnstr(haystack_ft, needle_ft, 9);
	if (result_ori != NULL)
		printf("Found at position: %ld\n", result_ori - haystack_ori);
	else
		printf("Not found\n");
	if (result_ft != NULL)
		printf("Found at position: %ld\n", result_ft - haystack_ft);
	else
		printf("Not found\n");
	return (0);
}
 */